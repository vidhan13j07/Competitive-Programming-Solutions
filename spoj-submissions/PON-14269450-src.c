#include<stdio.h>
#define ULL unsigned long long int
ULL mulmod(ULL a, ULL b, ULL c){
	ULL x = 0,y = a%c;
	
	while(b>0){
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b >>= 1;
	}
	
	return x;
}

ULL power(ULL a, ULL b, ULL c){
	ULL x = 1, y = a;
	
	while(b>0){
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b >>= 1;
	}
	
	return x;
}

int miller_rabin(ULL p, int it){
	if(p<2) return 0;
	if(p==2) return 1;
	if((p&1)==0) return 0;
	
	ULL s = p-1;
	while(s%2==0) s >>= 1;
	
	while(it--){
		ULL a = rand()%(p-1)+1,temp = s;
		ULL mod = power(a,temp,p);
		
		if(mod==-1 || mod==1) continue;
		
		while(temp!=p-1 && mod!=p-1){
			mod = mulmod(mod,mod,p);
			temp <<= 1;
		}
		
		if(mod!=p-1) return 0;
	}
	
	return 1;
}

int main(){
	int T;
	unsigned long long N;
	scanf("%d",&T);
	
	while(T--){
		scanf("%llu",&N);
		printf("%s\n",miller_rabin(N,18)? "YES" : "NO");
	}
	return 0;
}