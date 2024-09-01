// import java.util.ArrayList;

public class PointN extends Element{
    double []list;
    public int size;

    public PointN(){
        size=2;
        list=new double[2];
        list[0]=0.0;
        list[1]=0.0;
    }
    public PointN(int sz,double []arr){
        size=sz;
        list=new double[sz];
        for(int i=0;i<sz;i++){
            list[i]= arr[i];
        }
    }
    public PointN(int n){
        size=n;
        list=new double[n];
        for(int i=0;i<n;i++){
            double val=Math.random()*10;
            list[i]=val;
        }
    }
    public double Norm(){
        double ans=0;
        for(int i=0;i<size;i++){
            ans+=list[i]*list[i];
        }
        ans=Math.sqrt(ans);
        return Math.round(ans*1000.0)/1000.0;
    }
    @Override
    public void print() {
        for(int i=0;i<size;i++){
            System.out.print(list[i]+" ");
        }
    }


}
