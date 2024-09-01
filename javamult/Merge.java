public class Merge extends Thread{
    public int start;
    public int end;
    int [] arr;
    int n;
    public Merge(int []curr,int start,int end) {
        arr=curr;
        this.start=start;
        this.end=end;
    }
    public void run (){
        mergeSort(arr,start,end);
    }
     public void threadedSort (int nt,int []arr,int n) {

        int npt=(n+ nt-1)/nt;

        Thread[] threads=new Thread[nt];

        for (int i=0;i<nt;i++) {
            int start=i*npt;
            int end=Math.min(n,(i+1)*npt)-1;
            threads[i]=new Merge(arr,start,end);
            threads[i].start();
        }

        for (Thread thread : threads) {
            try {
              thread.join();
            } catch (InterruptedException e) {
              e.printStackTrace();
            }
        }
        int prevend=npt-1;
        for (int i=0;i<nt;i++) {
            int mid=prevend;
            int end=Math.min(n,(i+1)*npt)-1;
            merge(arr,0,mid,end);
            prevend=end;
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
    public static void main(String[] args) {
        
        int [] arr= {6,5,7,4,6,8,0,-3,4};
        int n=arr.length;

        Merge obj=new Merge(arr,0,n);
        obj.threadedSort(2,arr,n);

        for (int i=0;i<n;i++) {
            System.out.println(arr[i]);
        }

        // Integer x= new Integer(23);
        // System.out.println(x.getInteger());
    }
}
