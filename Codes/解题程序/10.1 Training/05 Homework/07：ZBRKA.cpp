#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 10005
#define MOD 1000000007
long long dp[LEN][LEN] , n , k ;

int main(){
	
	scanf ( "%lld %lld" , &n , &k ) ;

	dp[1][0] = 1 ;
	for ( int i = 2 ; i <= n ; i++ ) {
		long long sum = 0 ; // 动态统计前缀和部分的优化sum值
		for ( int j = 0 ; j <= k ; j++ ) {
            sum += dp[i - 1][j] , sum %= MOD , dp[i][j] = sum ;
            if ( j >= i - 1 ) {
                sum -= dp[i - 1][j - i + 1] ;
                sum %= MOD , sum += MOD , sum %= MOD ;
            }
        }
	}

    
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 0 ; j <= k ; j++ ) {
            // cout << dp[i][j] << " " ;
            printf ( "%6d" , dp[i][j] ) ;
        }
        cout << endl ;
    }
    
	
	printf ( "%lld" , dp[n][k] ) ;
	
	return 0 ;
}

/*
可以发现每行都是回文的，回文点在距离上一行的回文点+2的位置，回文规律是a[i][j] = a[i - 1][j] + a[i][j - 1] ;
     1     0     0     0     0     0     0     0     0     0     0
     1     1     0     0     0     0     0     0     0     0     0
     1    *2     2     1     0     0     0     0     0     0     0
     1     3     5    *6     5     3     1     0     0     0     0
     1     4     9    15    20   *22    20    15     9     4     1
     1     5    14    29    49    71    90  *101   101    90    71
     1     6    20    49    98   169   259   359   455  *531   573
     1     7    27    76   174   343   602   961  1415  1940  2493
     1     8    35   111   285   628  1230  2191  3606  5545  8031
     1     9    44   155   440  1068  2298  4489  8095 13640 21670
*/