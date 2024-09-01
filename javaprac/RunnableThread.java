

public class RunnableThread implements Runnable {
    private int no;
    public RunnableThread (int x) {
        no=x;
    }
    @Override
    public void run() {
        for (int i=0;i<=5;i++) {
            System.out.println(i + "; Thread: "+ this.no);
            try {
                Thread.sleep(1000);
                System.out.println(Thread.currentThread().getName());
            }catch (InterruptedException e) {

            }
            
            
        }
    }


}
