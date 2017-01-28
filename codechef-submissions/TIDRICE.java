/* package whatever; // don't place package name! */
import java.io.*;
/* Name of the class has to be "Main" only if the class is public. */
class Recipe
{
	public static void main (String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		String s;
		int t=Integer.parseInt(br.readLine());
		while(t>0)
		{
			t--;
			int i,j;
			int n=Integer.parseInt(br.readLine());
			String[] l=new String[n];
			String[] ar=new String[n];
			for(i=0;i<n;i++)
			{
				String str=br.readLine();
				String[] k=str.split(" ");
				l[i]=k[0];
				ar[i]=k[1];
			}
			String[] m=new String[n];
			int c=0,ans=0;
			for(i=n-1;i>=0;i--)
			{
				for(j=0;j<c;j++)
					if(m[j].equals(l[i]))
						break;
				if(j==c)
				{
					if(ar[i].equals("+"))
						ans+=1;
					else
						ans-=1;
					m[c]=l[i];
					c++;
				}
			}
			System.out.println(ans);
		}
	}
}
