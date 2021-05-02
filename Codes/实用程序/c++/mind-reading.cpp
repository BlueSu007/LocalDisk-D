#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <ctime>
using namespace std;

const int MAT[10][10][10]={{0},{{0,0,0,0,0},{0,1,3,5,7},{0,9,11,13,15},{0,17,19,21,23},{0,25,27,29,31}},
						{{0,0,0,0,0},{0,2,3,6,7},{0,10,11,14,15},{0,18,19,22,23},{0,26,27,30,31}},
						{{0,0,0,0,0},{0,4,5,6,7},{0,12,13,14,15},{0,20,21,22,23},{0,28,29,30,31}},
						{{0,0,0,0,0},{0,8,9,10,11},{0,12,13,14,15},{0,24,25,26,27},{0,28,29,30,31}},
						{{0,0,0,0,0},{0,16,17,18,19},{0,20,21,22,23},{0,24,25,26,27},{0,28,29,30,31}}};
int ans[6],secret[6]={0,1,2,4,8,16};

void middle(){
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"		";
}

void wait(int n){
	Sleep(n);
	system("cls");
	cout<<endl<<"		";
	cout<<"中国人民大学附属小学 新年联欢会专用小程序"<<endl; 
	cout<<"			";
	cout<<"展现精神：青色 创新精神"<<endl<<endl;
}

int main(){
	
	system("title 读心术小程序");
	
	middle();
	cout<<"欢迎进入新年联欢读心术小程序！祝大家新年快乐！"<<endl;
	wait(5000);
	
	middle();
	cout<<"正在启动……"<<endl;
	wait(5000);
	
	middle();
	cout<<"请您想一个1~31之间的数，不要说出来，一会儿会用到。"<<endl;
	wait(5000);
	
	while(1){
		for(int i=1;i<=5;i++){
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			
			if(i==1)	system("color 0D");
			if(i==2)	system("color 0C");
			if(i==3)	system("color 0E");
			if(i==4)	system("color 0A");
			if(i==5)	system("color 0B");
			
			for(int j=1;j<=4;j++){
				cout<<"				";
				for(int k=1;k<=4;k++){
					cout<<MAT[i][j][k]<<" ";
				}
				cout<<endl; 
			}
			cout<<"请找出这个矩阵中有没有您想的那个数，有的话输入1，没有输入0"<<endl;
			cin>>ans[i];
			
			system("color 0F");
			
			wait(500);
		}
		
		int sum=0,tmp;
		for(int i=1;i<=5;i++){
			if(ans[i]==1){
				sum+=secret[i];
			}
		}
		
		middle();
		cout<<"正在计算……"<<endl;
		wait(5000);
		
		middle();
		cout<<"您的数是"<<sum<<"，对吗？^_^"<<endl;
		wait(3000);
		
		middle();
		cout<<"还想玩吗？请输入操作码：1表示想，2表示不想"<<endl;
		cin>>tmp;
		
		if(tmp==1){
			ans[0]=ans[1]=ans[2]=ans[3]=ans[4]=ans[5]=0;
			wait(300);
			cout<<"请您再想一个1~32之间的数，不要说出来，一会儿会用到。"<<endl;
		}else if(tmp==2){
			middle();
			cout<<"游戏结束！>_<欢迎下次再玩！"<<endl;
			break;
		}else if(tmp!=1&&tmp!=2){
			cout<<"操作码不对，请重新输入操作码"<<endl;
			cin>>tmp;
			if(tmp!=1&&tmp!=2){
				wait(100);
				middle();
				cout<<"操作码不对导致系统瘫痪，游戏结束！>_<欢迎下次再玩！"<<endl;
				break;
			}
		}
	}
	
	return 0;
}
