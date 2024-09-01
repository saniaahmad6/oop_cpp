import java.util.*;

public class MergeSort {

    private static class SortThreads extends Thread {

        SortThreads (int arr[],int low, int high) {
            super(()-> {
                MergeSort.mergeSort(arr, low, high);
            });

            this.start();
        }
    }
    
    public static void threadedSort(int arr[]) {
        int n=arr.length;
        int MAX_THREADS=4;
        int partition=n/MAX_THREADS;
        boolean exact = (n%MAX_THREADS == 0) ? true: false;
        int maxlim = exact ? (n/MAX_THREADS) : (n/(MAX_THREADS-1));
        maxlim = (maxlim <MAX_THREADS) ?  MAX_THREADS: maxlim ;
        final ArrayList<SortThreads> list = new ArrayList<>();
        for (int i=0;i<n;i+=maxlim) {
            int beg=i;
            int remain=n-i;
            int end=(remain <MAX_THREADS) ? (i+remain-1) : (i+MAX_THREADS-1);
            final SortThreads t = new SortThreads(arr, beg, end);
            list.add(t);
        }

        for (Thread t: list) {
            try{
                t.join();
            }catch (InterruptedException e) {

            }
        }
        for (int i=0;i<n;i+=maxlim) {
            int mid=(i==0) ? 0 : i-1;
            int remain=n-i;
            int end=(remain <MAX_THREADS) ? (i+remain-1) : (i+MAX_THREADS-1);
            merge(arr, 0 , mid , end);
        }


    }
    public static void mergeSort (int arr[],int low, int high) {
        if (low<high) {
            int mid=(low+high)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }
    public static void merge (int arr[],int low,int mid,int high) {
        int i=low,j=mid+1,k=0;
        int temp[] = new int[high-low+1];

        while (i<=mid && j<=high) {
            if (arr[i]<=arr[j]) {
                temp[k++]=arr[i++];
            }else {
                temp[k++]=arr[j++];
            }
        }
        while (i<=mid)  temp[k++]=arr[i++];
        while (j<=high) temp[k++]=arr[j++];

        for (int cnt=0;cnt<(high-low+1);cnt++) {
            arr[cnt+low]=temp[cnt];
        }
    }
}
