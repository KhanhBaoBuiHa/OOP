//binary search
public class BinarySearch{
    public static int binarySearch(int[] arr, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);
        else return binarySearch(arr, mid + 1, right, target);
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 15};
        int target = 7;
        int index = binarySearch(arr, 0, arr.length - 1, target);
        if (index != -1)
            System.out.println("Find "+ target + " at " + index);
        else
            System.out.println("can not find");
    }
}
//binary tree
public class BinaryTree {
    public static class Node {
        int data;
        Node left, right;
    }
    public static binaryTree{
        Node root;
    }
    
}