#include <bits/stdc++.h>
using namespace std;

int num[1001001][5];

int main(){
	
	srand(time(NULL));
	
	int n;
	cout<<"需要几组数？"<<endl;
	cin>>n;
	 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			num[i][j]=rand()%13+1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			printf("%4d",num[i][j]);
		}
		cout<<endl;
	}
	
	return 0;
} 
