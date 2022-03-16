import java.util.*;

public class Strings {
    public static boolean check(long m, int K, int[] ropes) {
        int count = 0;
        for(int i = 0; i < ropes.length; ++i) {
            count += ropes[i] / m;
        }
        return count >= K;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] ropes = new int[N];
        long max  = 0;
        for(int i = 0; i < N; ++i) {
            ropes[i] = scanner.nextInt();
            max = ropes[i] > max ? ropes[i] : max;
        }
        Arrays.sort(ropes);
        long left = 0;
        long right = max + 1;
        while (right - left > 1) {
            long mid = (left + right) / 2;
            if (check(mid, K, ropes)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        System.out.println(left);
    }

}