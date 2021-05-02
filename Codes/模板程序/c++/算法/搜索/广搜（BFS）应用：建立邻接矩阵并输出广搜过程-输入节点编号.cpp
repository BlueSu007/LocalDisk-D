#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[500 + 5][500 + 5] ;
char v[500 + 5] ;
int n , m ;
inline void create_graphic () ;

int main() {
	
	ios::sync_with_stdio ( false ) ;
	cin >> m >> n ;
	create_graphic () ;
	
	for ( int i = 1 ; i <= m ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			cout << a[i][j] << " " ;
		}
		
		cout << endl ;
	}
}

inline void create_graphic () {
	
	char x , y ;
	for ( int i = 1 ; i <= m ; i++ ) {
		cin >> v[i] ;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> x >> y ;
		int q , p ;
		
		for ( int j = 1 ; j <= m ; j++ ) {
			if ( v[j] == x ) {
				q = j ;
				break ;
			}
		}
		
		for ( int j = 1 ; j <= m ; j++ ) {
			if ( v[j] == y ) {
				p = j ;
				break ;
			}
		}
		
		a[q][p] = 1 ;
	}
}

/*
5 6
1 2 3 4 5
1 2
1 3
1 5
2 4
3 5
4 5
*/ 
