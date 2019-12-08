import java.lang.Thread;
import java.util.Scanner;

class Fibonnaci extends Thread
{
    int[] a;
    int i;
    Fibonnaci(int[] a,int i)
    {
        this.a = a;
        this.i = i;
    }
    public void run()
    {
        try
        {
            if(this.i == 0)
            {
                this.a[this.i] = 0;
            }
            else if(this.i == 1)
            {
                this.a[this.i] = 1;
            }
            else
            {
                this.a[i] = this.a[i-1] + this.a[i-2];
            }
        }
        catch (Exception e)
        {
            System.out.println ("Exception : " + e);
        }
    }
}

public class thread_fibonnaci
{
    static int recursion(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
			return 1;
	 }
        return recursion(n-2) + recursion(n-1);
    }

    public static void main(String[] args)
    {
        try
        {
            Scanner s = new Scanner(System.in);
            System.out.println("Enter N : ");
            int N = s.nextInt();
            long begin = System.currentTimeMillis();
            int[] a = new int[N];
            for (int i=0; i<N; i++)
            {
                Fibonnaci obj = new Fibonnaci(a, i);
                obj.start();
                obj.join();
            }
            System.out.println("Multi-threaded Fibonacci:-");
            for(int i=0; i<N; i++)
            {
                System.out.print(a[i] + " ");
            }
            long end = System.currentTimeMillis();
            System.out.println("\nComputation Time: "+(end - begin) + " ms");
            System.out.println();
            begin = System.currentTimeMillis();
            System.out.println("Recursive Fibonacci:-");
            for(int i=0; i<N; i++)
            {
                System.out.print(recursion(i) + " ");
            }
            end = System.currentTimeMillis();
            System.out.println("\nComputation Time: "+(end - begin) + " ms");
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
