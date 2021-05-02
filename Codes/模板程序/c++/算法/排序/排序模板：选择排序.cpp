#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5];
int n;

void selection_sort();

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	selection_sort();
	
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	
	return 0;
}

void selection_sort(){
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[i] >= a[j])
				swap(a[i], a[j]);
		}
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

void selection_sort();

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	selection_sort();
	
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	
	return 0;
}

void selection_sort(){
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[i] >= a[j])
				swap(a[i], a[j]);
		}
		
		for(int j = 1; j <= n; j++){
			cout << a[j] << " ";
		}
		cout << endl;
	}
}
*/
//8 8 7 6 5 4 3 2 1
