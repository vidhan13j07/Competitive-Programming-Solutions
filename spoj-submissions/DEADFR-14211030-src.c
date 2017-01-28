#include <stdio.h>
#include<string.h>
#define ULL unsigned long long
ULL pow_10[19] = {1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000 , 10000000 , 100000000 , 1000000000 , 10000000000LL , 100000000000LL , 1000000000000LL , 10000000000000LL , 100000000000000LL , 1000000000000000LL , 10000000000000000LL , 100000000000000000LL , 1000000000000000000LL};
ULL __gcd(ULL a,ULL b)
{
	if(b==0)
		return a;
	else
		return __gcd(b,a%b);
}
int main()
{
    while(1)
    {
        char s[30] ;
        scanf("%s",s);
        if(s[0] == '0' && strlen(s) == 1)
            break;
        int i,j,len = strlen(s) - 5;
        int conslen = len;
        ULL num = 0 , consnum, denomeator , temp;
        for(i = 0 , j = 2; i  < len ;j++, i++)
            num = num*10 + s[j] - 48;
        consnum = num;
        ULL nume = 999999999999999999LL , deno = 999999999999999999LL;
        for(i = 0 ; i<conslen ; i++){
            temp = consnum - num / 10;
            denomeator = pow_10[conslen] - pow_10[len - 1];
            ULL gcd = __gcd(temp , denomeator);
            if((denomeator / gcd) < deno)
                deno = denomeator / gcd , nume = temp / gcd;
            num/=10;
            len--;
        }
        printf("%llu/%llu\n", nume, deno);
    }
    return 0;
}