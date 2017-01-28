/*
* @author FreeWifi_novicer
* language : C++/C
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>

using namespace std;

#define clr( x , y ) memset(x,y,sizeof(x))
#define cls( x ) memset(x,0,sizeof(x))
#define pr( x ) cout << #x << " = " << x << endl 
#define pri( x ) cout << #x << " = " << x << " " 
#define test( t ) int t ; cin >> t ; int kase = 1 ; while( t-- )
#define out( kase ) printf( "Case %d: " , kase++ )
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
typedef long long lint;
typedef long long ll;
typedef long long LL;

const int S = 8 ;
const int mod = 1e9 + 7 ;
lint multi_mod( lint a , lint b , lint c ){
    a %= c ; b %= c ;
    lint res = 0 ;
    while( b ){
        if( b & 1 ){
            res += a ;
            if( res > c ) res -= c ;
        }
        a <<= 1 ;
        if( a > c ) a-= c ;
        b >>= 1 ;
    }
    return res ;
}

lint pow_mod( lint x , lint n , lint p ){
    x %= p ;
    lint res = 1 ;
    while( n ){
        if( n & 1 )
            res = multi_mod( res , x , p ) ;
        n >>= 1 ;
        x = multi_mod( x , x , p ) ;
    }
    return res ;
}

bool check( lint a , lint n , lint x , lint t ){
    lint res = pow_mod( a , x , n ) ;
    lint last = res ;
    for( int i = 0 ; i < t ; i++ ){
        res = multi_mod( res , res , n ) ;
        if( res == 1 && last != 1 && last != n - 1 ) return true ;
        last = res ;
    }
    if( res != 1 ) return true ;
    return false ;
}

bool Miller_Rabin( lint n ){
    if( n < 2 ) return false ;
    if( n == 2 ) return true ;
    if( ( n & 1 ) == 0 ) return false ;
    lint x = n - 1 ;
    lint t = 0 ;
    while( ( x & 1 ) == 0 ){ x >>= 1 ; t++ ; }
    srand( time( NULL ) ) ;
    for( int i = 0 ; i < S ; i++ ){
        lint a = rand() % ( n - 1 ) + 1 ;
        if( check( a , n , x , t ) )
            return false ;
    }
    return true ;
}

lint factor[100] ;
int tol ;
lint gcd( lint a , lint b ){
    return ( b == 0 )? a : gcd( b , a % b ) ;
}

lint pollard_rho( lint x , lint c ){
    lint i = 1 , k = 2 ;
    srand( time( NULL ) ) ;
    lint x0 = rand() % ( x - 1 ) + 1 ;
    lint y = x0 ;
    while( 1 ){
        i++ ;
        x0 = ( multi_mod( x0 , x0 , x ) + c ) % x ;
        lint d = gcd( ( y - x0 + x ) % x , x ) ;
        if( d != 1 && d != x ) return d ;
        if( y == x0 ) return x ;
        if( i == k ){ y = x0 ; k += k ; }
    }
}
// k = 107
void findfac( lint n , lint k ){
    if( n == 1 ) return ;
    if( Miller_Rabin(n) ){
        factor[tol++] = n ;
        return ;
    }
    lint p = n ; 
    int c = k ;
    while( p >= n )
        p = pollard_rho( p , c-- ) ;
    findfac( p , k ) ;
    findfac( n / p , k ) ;
}

lint pf[100][2] ;
int getPrifac( lint n ){
    tol = 0 ;
    findfac( n , 107 ) ;
    sort( factor , factor + tol ) ;
    cls( pf ) ;
    pf[0][0] = factor[0] ;
    pf[0][1] = 1 ;
    int k = 0 ;
    for( int i = 1 ; i < tol ; i++ ){
        if( factor[i] != factor[i-1] ) pf[++k][0] = factor[i] ;
        pf[k][1] ++ ;
    }
    return k + 1 ;
}

lint calc( lint n ){
    int len = getPrifac( n ) ;
    lint res = 1 ;
    for( int i = 0 ; i < len ; i++ ){
        res = res % mod * ( pf[i][0] + 1 ) % mod ;
    }
    return res % mod ;
}
int main(){
//  freopen("input.txt","r",stdin);
    test(t) {
        lint n ;
        scanf( "%lld" , &n ) ;
        printf( "%lld\n" , calc(n) ) ;
        //calc(n);
    }
    return 0;
}