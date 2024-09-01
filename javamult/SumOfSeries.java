
public class SumOfSeries {
  private int n;
  private long result;

  public SumOfSeries(int n) {
    this.n = n;
    this.result = 0;
  }

  public synchronized void calcSum(int start, int end) {
    long sum = 0;
    for (int i = start; i <= end; i++) {
      sum += i;
    }
    // synchronized (this) {
    result += sum;
    // }
  }

  public void runThreads(int numThreads) {

    int numbersPerThread = (n + numThreads - 1) / numThreads; // Adjusted calculation
    Thread[] threads = new Thread[numThreads];

    // Launch threads
    for (int i = 0; i < numThreads; ++i) {
      int start = i * numbersPerThread + 1;
      int end = Math.min((i + 1) * numbersPerThread, n); // Adjusted calculation
      threads[i] = new Thread(() -> calcSum(start, end));
      threads[i].start();
    }
    for (Thread thread : threads) {
      try {
        thread.join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }

  public long getResult() {
    return result;
  }

  public static void main(String args[]) {
    // Thread t1 = new Thread(() -> calcSum());
    // Thread t2 = new Thread(() -> calcSum());
    // t1.start();
    // t2.start();
    // try {
    // t1.join();
    // t2.join();
    // } catch (InterruptedException e) {
    // System.out.println("Thread Interrupted");
    // }
    // System.out.println();
    // }
    SumOfSeries S1 = new SumOfSeries(6);
    S1.runThreads(4);
    System.out.println("sum is " + S1.getResult());

  }
}