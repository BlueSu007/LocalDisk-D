#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5];
int n;

void quick_sort(int left, int right);

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	quick_sort(1, n);
	
	for(int j = 1; j <= n; j++)
		cout << a[j] << " ";
	
	return 0;
}

void quick_sort(int left, int right){
	if(left >= right)
		return ;
	
	int i = left, j = right;
	int key = a[i];
	
	while(i < j){
		while(i < j && a[j] >= key)
			j--;
			
		while(i < j && a[i] <= key)
			i++;
			
		if(i < j)
			swap(a[i], a[j]);
	}
	
	swap(a[left], a[i]);
	
	quick_sort(left, i);
	quick_sort(i + 1, right);
} 
/*
//������̰�
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5];
int n;

void quick_sort(int left, int right);

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	quick_sort(1, n);
	
	for(int j = 1; j <= n; j++)
		cout << a[j] << " ";
	
	return 0;
}

void quick_sort(int left, int right){
	if(left >= right){
		cout << a[right] << endl;
		return ;
	}
	
	int i = left, j = right;
	int key = a[i];
	
	while(i < j){
		while(i < j && a[j] >= key)
			j--;
			
		while(i < j && a[i] <= key)
			i++;
			
		if(i < j)
			swap(a[i], a[j]);
	}
	
	swap(a[left], a[i]);
	
	for(int i = left; i <= right; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	
	quick_sort(left, i);
	quick_sort(i + 1, right);
}
*/ 
//8 8 7 6 5 4 3 2 1
