#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

stack < int > s;
int x , y;

int main() {
	
	while ( x != -1 ) {
		cin >> x;
		if ( x == 1 ) {
			cin >> y;
			s.push(y);
		}
		else if ( x == 2 ) {
			if ( !s.empty() ){
			   s.pop();
			}
			else {
				cout << "Emptied!" << endl;
			}
		}
		else if ( x == 3 ) {
			if ( !s.empty() ){
			   cout << s.top() << endl;
			}
			else {
				cout << "Emptied!" << endl;
			}
		}
		else if ( x == 4 ) {
			cout << s.empty() << endl;
		}
		
		cout << "----------------------" << endl;
	}
	
	return 0;
}
