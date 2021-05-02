// https://www.luogu.com.cn/blog/yh1127/solution-p1106
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

char s[250 + 5] ;
int n , len ;

int main () {

	scanf ( "%s %d" , s , &n ) ;
	len = strlen (s) ;

	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 0 ; j < len ; j++ ) {
			if ( s[j] > s[j + 1] ) {
				for ( int k = j ; k < len - 1 ; k++ ) {
					s[k] = s[k + 1] ;
				}
				break ;
			}
		}
		len-- ;
	}

	int i = -1 ;
	while ( i < len && s[++i] == '0' ) ;

	if ( i == len ) {
		printf ( "0" ) ;
	}
	else {
		for ( int j = i ; j < len ; j++ ) {
			printf ( "%c" , s[j] ) ;
		}
	}

	return 0 ;
}