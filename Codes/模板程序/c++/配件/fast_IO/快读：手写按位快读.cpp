#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

inline int read_(){
	int x = 0, f = 1;
	char ch = getchar();
	
	while(!isdigit(ch)){
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	
	while(isdigit(ch)){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x * f;
}

int main(){
	
	int a, b;
	a = read_();
	b = read_();
	
	cout << a + b << endl;
	
	return 0;
}
