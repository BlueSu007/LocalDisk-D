#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

inline void write( int x ) {
	if ( x >= 10 ) {
		write( x / 10 );
	}
	
	putchar( x % 10 + '0' );
}

int main(){
	
	int a, b;
	cin >> a >> b;
	write( a + b );
	
	return 0;
}
