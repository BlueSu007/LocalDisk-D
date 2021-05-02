/*
SPFA is the better version of Ford.
This code is use DFS to update SPFA.
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 0x7fffff
using namespace std;

int x , y , z , n , m , start , t;
int que[1000000 + 5] , dis[1000 + 5];
int a[1000 + 5][1000 + 5] , b[1000 + 5][1000 + 5];
bool vis[1000 + 5];
inline void SPFA ( int start );

int main() {
	
	scanf ( "%d %d %d" , &n , &m , &start );
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d %d" , &x , &y , &z );
		if ( a[x][y] != 0 && z > a[x][y] ) {
			continue;
		}
		
		b[x][0]++ , b[x][b[x][0]] = y , a[x][y] = z;
		b[y][0]++ , b[y][b[y][0]] = x , a[y][x] = z;
	}
	
	for ( int i = 0 ; i <= n ; i++ ) {
		dis[i] = INF;
	}
	
	dis[start] = 0;
	SPFA(start);
	
	for ( int i = 1 ; i <= n ; i++ ) {
		printf ( "%d " , dis[i] );
	}
	
	return 0;
}

inline void SPFA ( int start ) {
	for ( int i = 1 ; i <= b[start][0] ; i++ ) {
		if ( dis[b[start][i]] > dis[start] + a[start][b[start][i]] ) {
			dis[b[start][i]] = dis[start] + a[start][b[start][i]];
			SPFA ( b[start][i] );
		}
	}
}

/*
//luogu P4779
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

0 2 4 3
*/
