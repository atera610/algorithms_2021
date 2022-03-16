import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.sqrt;

public class Swamps {
    static class Point{
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int N = scanner.nextInt();
        List<Point> points = new ArrayList<>();
        int x, y;
        for(int i = 0; i < N; ++i) {
            x = scanner.nextInt();
            y = scanner.nextInt();
            points.add(new Point(x, y));
        }
        double[][] cost = new double[N + 2][N + 2];
        double[] dist = new double[N + 2];
        int[] prev = new int[N + 2];
        boolean[] used = new boolean[N + 2];
        for(int i = 0; i < N; ++i) {
            prev[i] = -1;
            dist[i] = Double.MAX_VALUE;
            used[i] = false;
            for(int j = 0; j < N; ++j) {
                cost[i][j] =  sqrt((points.get(i).x - points.get(j).x)*(points.get(i).x - points.get(j).x) + (points.get(i).y - points.get(j).y)*(points.get(i).y - points.get(j).y));
            }
            cost[i][N] = points.get(i).y;
            cost[N][i] = cost[i][N];
            cost[i][N + 1] = H - points.get(i).y;
            cost[N + 1][i] = cost[i][N];
        }
        dist[N] = 0;
        prev[N + 1] = -1;
        cost[N][N + 1] = H;
        cost[N + 1][N] = H;
        dist[N + 1] = Double.MAX_VALUE;
//        key -- number, value -- distance
        PriorityQueue<Map.Entry<Integer, Double>> queue = new PriorityQueue<>(Comparator.comparingDouble(Map.Entry::getValue));
        queue.add(new AbstractMap.SimpleEntry<>(N, 0d));
        while(!queue.isEmpty()) {
            Map.Entry<Integer, Double> temp = queue.poll();
            int v_num = temp.getKey();

            if (v_num == N + 1) {
                break;
            }
            if (used[v_num]) {
                continue;
            }
            used[v_num] = true;

            for (int u = 0; u < N + 2; ++u) {
                if (used[u]) {
                    continue;
                }
                if (dist[u] == Double.MAX_VALUE) {
                    dist[u] = dist[v_num] > cost[v_num][u] ? dist[v_num] : cost[v_num][u];
                    prev[u] = v_num;
                    queue.add(new AbstractMap.SimpleEntry<>(u, dist[u]));
                }
                if (dist[u] > dist[v_num] && dist[u] > cost[v_num][u]) {
                    dist[u] = dist[v_num] > cost[v_num][u] ? dist[v_num] : cost[v_num][u];
                    prev[u] = v_num;
                    queue.add(new AbstractMap.SimpleEntry<>(u, dist[u]));
                }
            }
        }
        System.out.printf("%.6f", dist[N + 1]);
    }

}