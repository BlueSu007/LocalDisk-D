#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5];
int n, tmp;

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> tmp;
		a[tmp]++;
	}
	
	for(int i = 1; i <= 100004; i++){
		if(a[i])
			cout << i << " ";
	}
	
	cout << endl;
	
	for(int i = 1; i <= 100004; i++){
		while(a[i]){
			cout << i << " ";
			a[i]--;
		}
	}
	
	return 0;
}
//16 8 7 6 5 4 5 6 5 4 3 2 8 9 8 7 6
