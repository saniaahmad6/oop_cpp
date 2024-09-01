

public class Main {
    public static void main (String [] args) {

        long time=System.currentTimeMillis();
        int [] arr = {7,6,5,4,3};
        MergeSort.threadedSort(arr);
        time  =  System.currentTimeMillis() - time;

        for (int i=0;i<arr.length;i++) {
            System.out.println(arr[i]);
        }

        System.out.println(time+ "ms");

    }
}
