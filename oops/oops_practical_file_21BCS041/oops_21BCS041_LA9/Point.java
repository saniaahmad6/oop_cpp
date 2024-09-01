public class Point extends Element{
    public double _x;
    public double _y;
    public Point(double x,double y){
        _x=x;
        _y=y;
    }
    public Point(){
        _x=0;
        _y=0;
    }
    public void print(){
        System.out.println("Coordinates of the point : " +_x+" "+_y);
    }
    public double distFrom(Point p){
        double dist=Math.sqrt(Math.pow(_x-p._x,2)+Math.pow(_y-p._y,2));
        return dist;
    }
    public static Point midPoint(Point p1,Point p2){
        double newX=(p1._x+p2._x)/2.0;
        double newY=(p1._y+p2._y)/2.0;
        Point temp=new Point(newX,newY);
        return temp;
    }
}
