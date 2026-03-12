import java.util.*;

class HalloumiBoxes {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            long n = scanner.nextLong();
            long k = scanner.nextLong();
            long[] arr = new long[(int)n];
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextLong();
            }
            long[] a = Arrays.copyOf(arr, arr.length);
            Arrays.sort(a);

            if (Arrays.equals(a, arr) || k > 1) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        scanner.close(); 
    }
}