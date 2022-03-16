import java.util.*;

public class IslandsState {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        boolean[] cities = new boolean[N];
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < N; ++i) {
            cities[i] = scanner.nextInt() == 1 ? true : false;
            adj.add(i, new ArrayList<>());
        }
        int a,b;
        for(int i = 0; i < M; ++i) {
            a = scanner.nextInt() - 1;
            b = scanner.nextInt() - 1;
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        int[] dist = new int[N];
        int[] prev = new int[N];
        boolean[] used = new boolean[N];
        for(int i = 0; i < N; ++i) {
            dist[i] = Integer.MAX_VALUE;
            prev[i] = -1;
            used[i] = false;
        }
        dist[0] = 0;
        Comparator<AbstractMap.SimpleEntry<Integer, Integer>> cmp = Comparator.comparingInt(Map.Entry::getValue);
        PriorityQueue<AbstractMap.SimpleEntry<Integer, Integer>> queue = new PriorityQueue<>(cmp);
        queue.add(new AbstractMap.SimpleEntry<>(0, 0));
        AbstractMap.SimpleEntry<Integer, Integer> entry;

        Integer v;
        int cost = 0;
        while(!queue.isEmpty()) {
            entry = queue.poll();
            v = entry.getKey();
            if(used[v]) {
                continue;
            }
            for (Integer u : adj.get(v)) {
                if(used[u]) {
                    continue;
                }
                if(cities[v] == cities[u]) {
                    cost = 0;
                } else if(v % 2 == 1) {
                    cost = 2;
                } else {
                    cost = 1;
                }
                if(dist[u] == Integer.MAX_VALUE) {
                    dist[u] = dist[v] + cost;
                    prev[u] = v;
                    queue.add(new AbstractMap.SimpleEntry<>(u, dist[u]));
                } else if (dist[u] > dist[v] + cost) {
                    dist[u] = dist[v] + cost;
                    prev[u] = v;
                    queue.add(new AbstractMap.SimpleEntry<>(u, dist[u]));
                }
            }
            used[v] = true;
        }
        if (dist[N - 1] == Integer.MAX_VALUE) {
            System.out.println("impossible");
            return;
        }
        List<Integer> result = new ArrayList<>();
        result.add(0, N);
        int x = N - 1;
        int i = 1;
        while(x != 0) {
            result.add(i, prev[x] + 1);
            i++;
            x = prev[x];
        }
        System.out.println(dist[N - 1] + " " + result.size());
        for(int j = result.size() - 1; j > -1 ; --j) {
            System.out.print(result.get(j) + " ");
        }
    }

}