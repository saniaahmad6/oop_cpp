import java.util.ArrayList;

public class MergeSortOptimized{

    // Assuming system has 4 logical processors
    private static final int MAX_THREADS = 4;

    // Custom Thread class with constructors
    private static class SortThreads extends Thread{
        SortThreads(PointN[] array, int begin, int end){
            super(()->{
                MergeSortOptimized.mergeSort(array, begin, end);
            });
            this.start();
        }
    }

    public static void threadedSort(PointN[] array){
        // For performance - get current time in millis before starting
        long time = System.currentTimeMillis();
        final int length = array.length;
        boolean exact = length%MAX_THREADS == 0;
        int maxlim = exact? length/MAX_THREADS: length/(MAX_THREADS-1);
        maxlim = maxlim < MAX_THREADS? MAX_THREADS : maxlim;
        final ArrayList<SortThreads> threads = new ArrayList<>();
        for(int i=0; i < length; i+=maxlim){
            int beg = i;
            int remain = (length)-i;
            int end = remain < maxlim? i+(remain-1): i+(maxlim-1);
            final SortThreads t = new SortThreads(array, beg, end);
            threads.add(t);
        }
        for(Thread t: threads){
            try{
                t.join();
            } catch(InterruptedException ignored){
                System.out.println("Thread Interrupted");
            }
        }
        for(int i=0; i < length; i+=maxlim){
            int mid = i == 0? 0 : i-1;
            int remain = (length)-i;
            int end = remain < maxlim? i+(remain-1): i+(maxlim-1);
            merge(array, 0, mid, end);
        }
        time = System.currentTimeMillis() - time;
    }


    public static void mergeSort(PointN[] array, int begin, int end){
        try{
            if (begin<end){
                int mid = (begin+end)/2;
                mergeSort(array, begin, mid);
                mergeSort(array, mid+1, end);
                merge(array, begin, mid, end);
            }
        }
        catch (IndexOutOfBoundsException e){
            System.out.println("Array index out of bound");
        }

    }

    //Typical 2-way merge
    public static void merge(PointN[] array, int begin, int mid, int end){
        PointN[] temp = new PointN[(end-begin)+1];

        int i = begin, j = mid+1;
        int k = 0;

        while(i<=mid && j<=end){
            if (array[i].normval <= array[j].normval){
                temp[k] = array[i];
                i+=1;
            }else{
                temp[k] = array[j];
                j+=1;
            }
            k+=1;
        }

        while(i<=mid){
            temp[k] = array[i];
            i+=1; k+=1;
        }

        while(j<=end){
            temp[k] = array[j];
            j+=1; k+=1;
        }

        for(i=begin, k=0; i<=end; i++,k++){
            array[i] = temp[k];
        }
    }
}
