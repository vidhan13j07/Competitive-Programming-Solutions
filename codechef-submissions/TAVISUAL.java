import java.io.*;
class Ballandcups
{
        public static void main(String[] args)throws IOException
        {
                BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
                int t=Integer.parseInt(br.readLine());
                while(t>0)
                {
                        t--;
                        int n,c,q,l,r,temp;
                        String[] ar=br.readLine().split(" ");
                        n=Integer.parseInt(ar[0]);
                        c=Integer.parseInt(ar[1])-1;
                        q=Integer.parseInt(ar[2]);
                        while(q>0)
                        {
                                q--;
                                String[] ar1=br.readLine().split(" ");
                                l=Integer.parseInt(ar1[0])-1;
                                r=Integer.parseInt(ar1[1])-1;
                                if(c>=l && c<=r)
                                {
                                        temp=c-l;
                                        c=r-temp;
                                }
                        }
                        c+=1;
                        System.out.println(c);
                }
        }
}
