#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int a[10000],n;
string name[10000];

int main(){
	
	cout<<"请输入学生人数："<<endl;
	cin>>n; 
	
	int max1=-1,min1=0x7fffffff,cnt=0;
	
	cout<<"请输入学生分数："<<endl;
	for(int i=1;i<=n;i++){
		cin>>name[i]>>a[i];
		
		if(a[i]>max1) max1=a[i];
		if(a[i]<min1) min1=a[i];
		
		cnt+=a[i];
		
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				swap(name[i],name[j]);
			}
		}
	}
	
	for(int i=1;i>=n;i++){
		cout<<name[i]<<a[i]<<endl;
	}
	
	cout<<"最高分："<<max1<<endl;
	cout<<"最低分："<<min1<<endl;
	
	cout<<"总分："<<cnt<<endl;
	cout<<"平均分："<<cnt/(double)n<<endl;
	
	return 0;
}
