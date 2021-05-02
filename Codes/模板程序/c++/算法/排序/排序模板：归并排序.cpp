#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a[100000 + 5], b[100000 + 5];
void fen(int left, int right);
void bing(int left, int right, int mid);

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	fen(0, n - 1);
	 
	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}

void fen(int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		fen(left, mid);
		fen(mid + 1, right);
		bing(left, right, mid);
	}
}

void bing(int left, int right, int mid){
	int i, j, k;
	i = left, j = mid + 1, k = 0;
	
	while(i <= mid && j <= right){
		if(a[i] < a[j]){
			b[k++] = a[i++];
		}else{
			b[k++] = a[j++];
		}
	}
	
	while(i <= mid){
		b[k++] = a[i++];
	}
	
	while(j <= right){
		b[k++] = a[j++];
	}
	
	for(int i = 0; i < k; i++)
		a[left + i] = b[i];
}
/*
//Êä³ö¹ý³Ì°æ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a[100000 + 5], b[100000 + 5];
void fen(int left, int right);
void bing(int left, int right, int mid);

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	fen(0, n - 1);
	 
	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}

void fen(int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		fen(left, mid);
		fen(mid + 1, right);
		bing(left, right, mid);
	}
}

void bing(int left, int right, int mid){
	int i, j, k;
	i = left, j = mid + 1, k = 0;
	
	while(i <= mid && j <= right){
		if(a[i] < a[j]){
			b[k++] = a[i++];
		}else{
			b[k++] = a[j++];
		}
	}
	
	while(i <= mid){
		b[k++] = a[i++];
	}
	
	while(j <= right){
		b[k++] = a[j++];
	}
	
	for(int i = 0; i < k; i++){
		a[left + i] = b[i];
		cout << a[left + i] << " ";
	}
	
	cout << endl;
}
*/
//8 8 7 6 5 4 3 2 1
