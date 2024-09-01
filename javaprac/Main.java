
public class Main {
    public static void main (String [] args) {
        System.out.println("Welcome");

        for (int i=0;i<3;i++) {
            // Multithread t=new Multithread(i);
            // t.start();

            RunnableThread t=new RunnableThread(i);
            Thread currThread = new Thread(t);
            currThread.start();
            try {
                currThread.join(); //waits for the threads to end
            }catch (InterruptedException e) {

            }
            

        }
    } 
}
