import java.util.*;

class Q17 {

    public static float clinicPerVillage(int[] arr, int k, PriorityQueue<int[]> pq) {

        while (k > 0) {
            int[] curr = pq.poll();
            pq.add(new int[]{curr[0], curr[1] + 1});
            k--;
        }

        int[] worst = pq.peek();
        return (float) worst[0] / (float) worst[1];
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of villages : ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        System.out.print("Enter the population in villages : ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter the number of clinics available : ");
        int k = sc.nextInt();

        if (k < n) {
            System.out.println("Error: need at least one clinic per village (k must be >= n).");
            return;
        }

        k -= n;

        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> Double.compare((double) b[0] / b[1], (double) a[0] / a[1])
        );

        for (int i = 0; i < n; i++) {
            pq.add(new int[]{arr[i], 1});
        }

        System.out.printf("%.2f", clinicPerVillage(arr, k, pq));
    }
}