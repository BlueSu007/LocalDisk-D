#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	
	int n;
	
	while(!cin.eof()){
		cin>>n;
		int flag=0;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				cout<<"NO"<<endl;
				cout<<"It have "<<i<<" and "<<n/i<<" ."<<endl;
				cout<<endl;
				flag=1;
				break;
			}
		}
		if(!flag){
			cout<<"YES"<<endl<<endl;
		}
	}
	
	
	return 0;
} 
