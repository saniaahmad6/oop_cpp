

public class PointMain {

    public static void main(String[] args) {

        // 2 new points are created
        Point p=new Point(0,0),q=new Point(5,5);

        //finding the distance between points p & q
        System.out.println("Dist. between the points is : " + p.distFrom(q));

        //finding the midPoint of the points p & q
        Point n=Point.midPoint(p,q);
        n.print();

        // Problem 3
        Element[] ele=new Element[10000];
        for(int i=0;i<10000;i++){
            double x=Math.random()*100,y=Math.random()*100;
            Point newPoint=new Point(x,y);
            ele[i]=newPoint;
        }

        //Calculating centroid
        double X=0,Y=0;
        for(int i=0;i<10000;i++){
            if(ele[i] instanceof Point){
                Point temp= (Point) ele[i];
                X+=temp._x;
                Y+=temp._y;
            }
        }
        System.out.println("Centroid of 10000 points : ( " + X/10000.0 + " , " + Y/10000.0 + " )" );
    }
}
