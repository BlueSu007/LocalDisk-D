#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int f(int n){
	if(n==2)	return 1;
	if(n==1)	return 0;
	return f(n-1)+pow(2,n-2);
}

int main(){
	
	int n;
	cin>>n;
	
	cout<<pow(2,n-1)+f(n)+2<<endl;
	
	return 0;
}
