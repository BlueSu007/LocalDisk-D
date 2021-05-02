#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string s[100] , maxStr ;
int vis[100] , maxLen , n ;
inline int getCoverLen ( string s1 , string s2 ) ;
inline void dfs ( string nowStr , int nowLen ) ;

int main () {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 0 ; i <= n ; i++ ) {
		cin >> s[i] ;
	}
	
	dfs ( ' ' + s[n] , 1 ) ;
	printf ( "%d" , maxLen ) ;
	
	return 0 ;
}

inline int getCoverLen ( string s1 , string s2 ) {
	int len1 = s1.size () , len2 = s2.size () ;
	int len = min ( s1.size () , s2.size () ) ;
	
	for ( int i = 1 ; i < len ; i++ ) {
		int flag = true ;
		for ( int j = 0 ; j < i ; j++ ) {
			if ( s1[len1 - i + j] != s2[j] ) {
				flag = false ;
			}
		}
		
		if ( flag ) {
			return i ;
		}
	}
	
	return 0 ;
}

inline void dfs ( string nowStr , int nowLen ) {
	if ( nowLen > maxLen ) {
		maxLen = nowLen ;
	}
	for ( int i = 0 ; i < n ; i++ ) {
		if ( vis[i] >= 2 ) {
			continue ;
		}
		
		int len = getCoverLen ( nowStr , s[i] ) ;
		if ( len > 0 ) {
			vis[i]++ ;
			dfs ( s[i] , nowLen + s[i].size () - len ) ;
			vis[i]-- ;
		}
	}
}