#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int dis[1000 + 5] , n , m , u[1000 + 5] , v[1000 + 5] , w[1000 + 5];
const int INF = 0x7fffff;

int main() {
	
	scanf ( "%d %d" , &n , &m );
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d %d" , &u[i] , &v[i] , &w[i] ); 
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		dis[i] = INF;
	}
	
	dis[1] = 0;
	
	for ( int k = 1 ; k < n ; k++ ) {
		for ( int i = 1 ; i <= m ; i++ ) {
			if ( dis[v[i]] > dis[u[i]] + w[i] ) {
				dis[v[i]] = dis[u[i]] + w[i];
			}
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		printf ( "%d " , dis[i] );
	}
	
	return 0; 
}

/*
//aha!algorithm P168~P169
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3

0 -3 -1 2 4
*/
