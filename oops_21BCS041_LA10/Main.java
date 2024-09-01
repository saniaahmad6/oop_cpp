
public class Main {
    public static void merge(PointN [] arr,int l,int m,int h){
        int i=l,j=m+1,k=0;
        PointN[] temp=new PointN[h-l+1];
        while(i<=m && j<=h){
            if(arr[i].Norm() <= arr[j].Norm()){
                temp[k++]=arr[i++];
            }
            else temp[k++]=arr[j++];
        }
        while(i<=m)temp[k++]=arr[i++];
        while(j<=h)temp[k++]=arr[j++];

        for(int x=0;x<(h-l+1);x++){
            arr[x+l]=temp[x];
        }
    }
    public static void MergeSort(PointN [] arr,int l,int h){
        if(l>=h)return;
        int m=(l+h)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,h);

        merge(arr,l,m,h);
    }

    public static void timeChecker(int size,boolean multithreaded){
        PointN[] points=new PointN[size];
        for(int i=0;i<size;i++){
            points[i]=new PointN(5);
        }
        double s1=System.currentTimeMillis();
        if(multithreaded)MergeSort.threadedSort(points);
        else MergeSort(points,0,size-1);
        double e1=System.currentTimeMillis();
        System.out.println(((multithreaded)?"Multi-Threaded Time :": "Single-Threaded Time : ") + (e1-s1)+" ms");
    }

    public static void main(String[] args) {


        for(int i=10;i<=10000000;i*=10){
            System.out.println("For size : "+i+" ");
            // Time taken for single threaded
            timeChecker(i,false);
            // TIme taken for multithreaded
            timeChecker(i,true);
            System.out.println();
        }



    }
}