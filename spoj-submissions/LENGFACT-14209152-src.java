import java.util.Scanner;
public class Main 
{
    public static void main(String [] args)
    {
    	long n,ans;
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            n = sc.nextLong();
            if(n < 2)
                System.out.println(1);
            else
            {
                ans = (long)Math.floor((Math.log10(2*Math.PI*n) / 2 + n*(Math.log10(n) - Math.log10(Math.E))) + 1);
                System.out.println(ans);
            }

        }
    }
}