import java.util.*;

public class HorsePath {
    static int[][] next;
    static int[][] dist;

    /**
     * a b  c  d  e  f  g  h
     * 8 16 24 32 40 48 56 64
     * 7 15 23 31 39 47 55 63
     * 6 14 22 30 38 46 54 62
     * 5 13 21 29 37 45 53 61
     * 4 12 20 28 36 44 52 60
     * 3 11 19 27 35 43 51 59
     * 2 10 18 26 34 42 50 58
     * 1 9  17 25 33 41 49 57
     *
     */

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String one = in.next();
        String two = in.next();
        int start = 8*(one.charAt(0) - 'a')
                + one.charAt(1) - '0';
        int finish = 8*(two.charAt(0) - 'a')
                + two.charAt(1) - '0';
        int current;
        Deque<Integer> queue = new ArrayDeque<>();
        queue.add(start);
        int v;
        int[] parent = new int[65];
        boolean[] visited = new boolean[65];
        for(int i = 0; i < 65; ++i) {
            visited[i] = false;
        }
        visited[start] = true;
        while (!queue.isEmpty()) {
            current = queue.poll();
            if(current == finish) {
                break;
            }
            //small right long top
            if(current < 57 && current % 8 != 7 && current % 8 != 0) {
                v = current + 10;
                if(!visited[v]) {
                    queue.add(v);
                    parent[v] = current;
                    visited[v] = true;
                }
            }

            //small right long bottom
            if(current < 57 && current % 8 != 1 &&  current % 8 != 2) {
                v = current + 6;
                if(!visited[v]) {
                    queue.add(v);
                    parent[v] = current;
                    visited[v] = true;
                }
            }

            //long right small bottom
            if(current < 49 && current % 8 != 1) {
                v = current + 15;
                if(!visited[v]) {
                    queue.add(v);
                    parent[v] = current;
                    visited[v] = true;
                }
            }

            //long right small top
            if(current < 49 && current % 8 != 0) {
                v = current + 17;
                if(!visited[v]) {
                    queue.add(v);
                    parent[v] = current;
                    visited[v] = true;
                }
            }

            //small left long top
            if(current > 8 && current % 8 != 7 && current % 8 != 0) {
                v = current - 6;
                if(!visited[v]) {
                    queue.add(v);
                    parent[v] = current;
                    visited[v] = true;
                }
            }

            //small left long bottom
            if(current > 8 && current % 8 != 1 &&  current % 8 != 2) {
                v = current - 10;
                if(!visited[v]) {
                    queue.add(v);
                    parent[v] = current;
                    visited[v] = true;
                }
            }

            //long left small bottom
            if(current > 16 && current % 8 != 1) {
                v = current - 17;
                if(!visited[v]) {
                    queue.add(v);
                    parent[v] = current;
                    visited[v] = true;
                }
            }

            //long left small top
            if(current > 16 && current % 8 != 0) {
                v = current - 15;
                if(!visited[v]) {
                    queue.add(v);
                    parent[v] = current;
                    visited[v] = true;
                }
            }
        }
        List<Integer> result = new ArrayList<>();
        current = finish;
        result.add(finish);
        while(current != start) {
            current = parent[current];
            result.add(current);
        }
        char letter, number;
        for(int i = result.size() - 1; i > -1; --i) {
            current = result.get(i);
            letter = current % 8 == 0 ? (char) (current / 8 - 1+ 'a'): (char) (current / 8 + 'a');
            number =  current % 8 == 0 ? '8' : (char) (current % 8 + '0');

            System.out.print(letter);
            System.out.print(number);
            System.out.print("\n");
        }
    }

}