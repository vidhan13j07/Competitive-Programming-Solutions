import java.io.*;
 
class Translations
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		//PrintWriter pw=new PrintWriter(System.out);
		
		char arr[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		char arr2[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		String[] input=br.readLine().split(" ");
		
		int t=Integer.parseInt(input[0]);
		String s=input[1];
		char m,n;
 
		int i,j;
		while(t!=0)
		{
			String a=br.readLine();
				
			for(i=0;i< a.length();i++)
			{
				for(j=0;j<26;j++)
				{
				    m=a.charAt(i);
					if(a.charAt(i)== arr[j])
					{
						System.out.print(s.charAt(j));
						break;
					}
					else if(a.charAt(i) == arr2[j])
					{
					    n=s.charAt(j);
					    n=(char)(n-32);
						System.out.print(n);
						break;
					}
					else if(a.charAt(i)== '_')
					{
						System.out.print(" ");
						break;
					}
					else if(m=='.' || m==',' || m=='!' || m=='?')
					{
						System.out.print(a.charAt(i));
						break;
					}
				}
			}
			System.out.println();
			t--;
		}
	}
}
