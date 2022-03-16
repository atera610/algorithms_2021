import java.util.*;

public class Floid {
    static int[][] next;
    static int[][] dist;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        next = new int[n][n];
        dist = new int[n][n];
        int l;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                l = in.nextInt();
                dist[i][j] = l;
                next[i][j] = j;
            }
        }

        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                System.out.print(dist[i][j] + " ");
            }
            System.out.print("\n");
        }
    }

}