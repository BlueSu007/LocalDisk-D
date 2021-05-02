#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int s[1000 + 5];
int x , y , top = -1;
inline void push ( int x );
inline void pop();
inline int top_();
inline bool empty();
inline void print();

int main() {
	
	while ( x != -1 ) {
		cin >> x;
		if ( x == 1 ) {
			cin >> y;
			push(y);
		}
		else if ( x == 2 ) {
			pop();
		}
		else if ( x == 3 ) {
			cout << top_() << endl;
		}
		else if ( x == 4 ) {
			cout << empty() << endl;
		}
		else if ( x == 5 ) {
			print();
		}
		else if ( x == 6 ) {
			top = -1;
		}
		
		cout << "----------------------" << endl;
	}
	
	return 0;
}

inline void push ( int x ) {
	top++ , s[top] = x;
}

inline void pop() {
	if ( !empty() ) {
		top--;
	}
	else {
		cout << "Emptied!" << endl;
	}
}

inline int top_() {
	if ( !empty() ) {
		return s[top];
	}
	else {
		cout << "Emptied!" << endl;
	}
}

inline bool empty() {
	if ( top > -1 ) {
		return false;
	}
	
	return true;
}

inline void print() {
	if ( !empty() ) {
		for ( int i = 0 ; i <= top ; i++ ) {
			cout << s[i] << " ";
		}
		
		cout << endl;
	}
	else {
		cout << "Emptied!" << endl;
	}
}
