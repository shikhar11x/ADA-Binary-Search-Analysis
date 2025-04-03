import java.util.*;

public class BinarySearchAnalysis {
    static int stepCount = 0;

    public static int recursiveBinarySearch(int[] arr, int left, int right, int target) {
        stepCount++;
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] > target) return recursiveBinarySearch(arr, left, mid - 1, target);
            else return recursiveBinarySearch(arr, mid + 1, right, target);
        }
        return -1;
    }

    public static void analyzeBinarySearchRecursive() {
        int[] inputSizes = {10, 20, 30, 40, 50, 100};
        Random rand = new Random();

        for (int size : inputSizes) {
            int[] arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = i + 1;
            }

            int bestCase = arr[(size - 1) / 2];
            int worstCase = arr[size - 1];
            int randomCase = arr[rand.nextInt(size)];

            System.out.println("=================== Input Size: " + size + " ===================");
            stepCount = 0;
            recursiveBinarySearch(arr, 0, size - 1, bestCase);
            System.out.println("Best Case= " + stepCount + " steps");
            
            stepCount = 0;
            recursiveBinarySearch(arr, 0, size - 1, randomCase);
            System.out.println("Average Case= " + stepCount + " steps");
            
            stepCount = 0;
            recursiveBinarySearch(arr, 0, size - 1, worstCase);
            System.out.println("Worst Case= " + stepCount + " steps");
            
            System.out.println("===================================================================\n");
        }
    }

    public static void main(String[] args) {
        analyzeBinarySearchRecursive();
    }
}
