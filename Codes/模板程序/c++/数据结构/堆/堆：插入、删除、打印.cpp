#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int heap[100000 + 5], len;
int m, n, x, tmp;
inline void push( int x );
inline void pop();
inline void print();

int main() {
	
	ios::sync_with_stdio( false );
	cin >> len >> n;
	
	for ( int i = 1 ; i <= len ; i++ ) {
		cin >> heap[i];
	}
	
	while ( n-- ) {
		cin >> tmp;
		if ( tmp == 1 ) {
			cin >> x;
			push(x);
		}
		else if ( tmp == 2 ) {
			pop();
		}
		else if ( tmp == 3 ) {
			print();
		}
	}
	
	return 0;
}

inline void push( int x ) {
	
	int son, tmp;
	len++;
	
	heap[len] = x;
	son = len;
	
	while ( son != 1 && ( heap[son / 2] > heap[son] ) ) {
		tmp = heap[son / 2];
		heap[son / 2] = heap[son];
		heap[son] = tmp;
		son = son / 2;
	}
}

inline void pop() {
	
	int parent = 1, son, tmp;
	heap[1] = heap[len];
	len--;
	
	while ( parent * 2 <= len ) {
		if ( ( parent * 2 + 1 > len ) || ( heap[parent * 2] < heap[parent * 2 + 1] ) ) {
			son = parent * 2;
		}
		else {
			son = parent * 2 + 1;
		}
		
		if ( heap[parent] > heap[son] ) {
			tmp = heap[parent];
			heap[parent] = heap[son];
			heap[son] = tmp;
			parent = son;
		}
		else {
			return ;
		}
	}
}

inline void print() {
	for ( int i = 1 ; i <= len ; i++ ) {
		cout << heap[i] << " ";
	}
}

/*
5 6
1 2 3 4 5
1 6
1 9
1 8
3
1 4
3
*/
