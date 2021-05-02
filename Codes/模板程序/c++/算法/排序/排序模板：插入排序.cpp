#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5];
int n;

void insert_sort();

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	insert_sort();
	
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	
	return 0;
} 

void insert_sort(){
	for(int i = 1; i <= n; i++){
		int x = a[i];
		int j = i - 1;
		
		while(x < a[j]){
			a[j + 1] = a[j];
			j--;
		}
		
		a[j + 1] = x;
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

void insert_sort();

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	insert_sort();
	
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	
	return 0;
} 

void insert_sort(){
	for(int i = 1; i <= n; i++){
		int x = a[i];
		int j = i - 1;
		
		while(x < a[j]){
			a[j + 1] = a[j];
			j--;
		}
		
		a[j + 1] = x;
		
		for(int j = 1; j <= n; j++)
			cout << a[j] << " ";
		cout << endl; 
	}
} 
*/ 
//8 8 7 6 5 4 3 2 1
