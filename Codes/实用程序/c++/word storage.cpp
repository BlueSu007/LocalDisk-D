#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <windows.h>
using namespace std;

int id[1000];
int want[1000];
string word[1000];
string meaning[1000];

int main(){
	
	int url=20,cnt=1;
	cout<<"Welcome to tini words storage!"<<endl;
	cout<<"It can storage 999 words!"<<endl;
	
	while(url!=0){
		
		cout<<"input url:"<<endl;
		
		cout<<"0=退出"<<endl; 
		cout<<"1=存储"<<endl;
		cout<<"2=展示"<<endl;
		cout<<"3=查询"<<endl;
		cout<<"4=清屏"<<endl;
		
		cin>>url;
		
		if(url==0)	break;
		else if(url==1){
			cout<<"input wordcount:"<<endl;
			
			int n;
			cin>>n;
			
			for(int i=1;i<=n;i++){
				cout<<i<<" input word/meaning:";
				id[cnt]=cnt;
				cin>>word[cnt];
				cin>>meaning[cnt];
				cnt++;
			}
			
			cout<<"-------------------------"<<endl;
		}else if(url==2){
			cout<<"input id(like:2 7,if all want,input 0 0):"<<endl;
			int a,b,n,m;
			cin>>a>>b;
			if(a==b&&b==0){
				n=1,m=cnt;
			}else if(a==0||b==0){
				n=1,m=cnt;
			}else{
				n=a,m=b;
			}
			for(int i=n;i<=m;i++){
				cout<<id[i]<<"	"<<word[i]<<"	"<<meaning[i]<<endl;
			}
			cout<<"-------------------------"<<endl;
		}else if(url==3){
			cout<<"input wordcount:"<<endl;
			
			int w=1;
			cin>>w;
			
			for(int i=1;i<=w;i++){
				cin>>want[i];
			}
			
			for(int i=1;i<=w;i++){
				cout<<word[want[i]];
				if(i==w)	cout<<'.'<<endl;
				cout<<" ";
			}
			
			for(int i=1;i<=w;i++){
				cout<<meaning[want[i]];
				if(i==w)	cout<<"。"<<endl;
			}
			
			memset(want,0,sizeof(want));
			cout<<"-------------------------"<<endl;
		}else if(url==4){ 
			Sleep(100);
			system("cls");
		}else{
			cout<<"Please enter a valid url!"<<endl;
			cout<<"-------------------------"<<endl;
		}
		 
	}
	
	return 0;
} 
