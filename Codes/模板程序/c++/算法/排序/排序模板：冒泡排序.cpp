#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5];
int n;

void buble_sort();

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	buble_sort();
	
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	
	return 0;
}

void buble_sort(){
	bool flag = true;
	
	for(int i = 1; i <= n; i++){
		flag = true;
		for(int j = 1; j <= n - i; j++){
			if(a[j] > a[j + 1])
				swap(a[j], a[j + 1]), flag = false;
		}
		
		if(flag)
			break;
	}
}
/*
//Êä³ö¹ý³Ì°æ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5];
int n;

void buble_sort();

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	buble_sort();
	
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	
	return 0;
}

void buble_sort(){
	bool flag = true;
	
	for(int i = 1; i <= n; i++){
		flag = true;
		for(int j = 1; j <= n - i; j++){
			if(a[j] > a[j + 1])
				swap(a[j], a[j + 1]), flag = false;
		}
		
		if(flag)
			break;
			
		for(int j = 1; j <= n; j++)
			cout << a[j] << " ";
		cout << endl; 
	}
}
*/
//8 8 7 6 5 4 3 2 1
