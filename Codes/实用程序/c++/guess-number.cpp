#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void wait(int n);
void middle();
int ask(bool url);
int correct(int cnt);
void wrong(int ans,int real,int url);

int main(){
	
	srand(time(NULL));
	system("title 猜数小游戏"); 
	
	int n,guess,real;
	middle();
	cout<<"欢迎进入新年联欢猜数小程序！祝大家新年快乐！"<<endl;
	wait(5000);
	
	middle(); 
	cout<<"正在启动……"<<endl;
	wait(5000);
	
	n=ask(false);
	real=rand()%n+1;
	
	int cnt=0;
	
	while(1){
		cout<<"请输入您猜的数：\n";
		cin>>guess;
		cnt++;
		
		if(guess!=real){
			wrong(guess,real,0);
		}else{
			int tmp;
			tmp=correct(cnt);
			if(!tmp)	break;
			else	real=tmp;
			cnt=0;
		}
	}
	
	return 0;
}

void wait(int n){
	Sleep(n);
	system("cls");
	cout<<endl<<"		";
	cout<<"中国人民大学附属小学 新年联欢会专用小程序"<<endl; 
	cout<<"			";
	cout<<"展现精神：青色 创新精神"<<endl<<endl;
}

void middle(){
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"		";
}

int ask(bool url){
	int n=3;
	
	if(url){
		middle();
		cout<<"还想再玩吗？请输入操作码：1：想	2：不想"<<endl;
		cin>>n;
		
		if(n==1){
			system("cls");
			cout<<"请输入范围：（2<=n<=1000000）\n";
			cin>>n;
			return rand()%n+1;
		}else if(n==2){
			cout<<"游戏结束！>_< 欢迎下次再玩！"<<endl;
			return 0;
		}else{
			cout<<"操作码不对，请重新输入操作码：\n1：想	2：不想"<<endl;
		}
	}else{
		cout<<"请输入范围：（2<=n<=1000000）\n";
		cin>>n;
		
		srand(time(NULL));
		return rand()%n+1;
	}
}

int correct(int cnt){
	system("color 02");
	wait(1000);
	
	middle();
	cout<<"恭喜！答对啦！用了"<<cnt<<"次"<<endl;
	wait(2000);
	system("color 0F");
	
	return ask(true);
}

void wrong(int ans,int real,int url){
	
	if(url)	return ;
	
	system("color 0C");
	Sleep(500);
	
	if(ans>real){
		cout<<"您猜的数大了，请调整"<<endl;
		cout<<"--------------"<<endl;
	}else{
		cout<<"您猜的数小了，请调整"<<endl; 
		cout<<"--------------"<<endl;
	}
	
	Sleep(500);
	system("color 0F");
	
}
