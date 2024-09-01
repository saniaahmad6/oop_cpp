import java.util.ArrayList;

public class PointN extends Element{
    double []list;
    public int size;
    public double normval;

    public PointN(){
        size=2;
        list=new double[2];
        list[0]=0.0;
        list[1]=0.0;
        normval=0;
    }
    public PointN(int sz,double []arr){
        size=sz;
        list=new double[sz];
        normval=0;
        for(int i=0;i<sz;i++){
            list[i]= arr[i];
            normval+=(arr[i]*arr[i]);
        }
        normval=Math.round(Math.sqrt(normval)*1000.0)/1000.0;
    }
    public PointN(int n){
        size=n;
        list=new double[n];
        normval=0;
        for(int i=0;i<n;i++){
            double val=Math.random()*10;
            list[i]=val;
            normval+=(val*val);
        }
        normval=Math.round(Math.sqrt(normval)*1000.0)/1000.0;
    }
    public double Norm(){
        try {
            double ans=0;
            for(int i=0;i<size;i++){
                ans+=list[i]*list[i];
            }
            ans=Math.sqrt(ans);
            return Math.round(ans*1000.0)/1000.0;
        }
        catch (ArithmeticException e){
            System.out.println("Division by zero");
            return 0;
        }
    }
    @Override
    public void print() {
        for(int i=0;i<size;i++){
            System.out.print(list[i]+" ");
        }
    }


}
