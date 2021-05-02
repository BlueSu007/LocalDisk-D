/*
Unfinshed
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <windows.h>
#include <cstdlib>
using namespace std;

void print_map();//打印地图 
void check();//确定棋子位置，保证必胜策略
int five_piece();//如果对手已经连成五颗棋子，返回1；如果我连成五颗棋子，返回2；否则0 
void cls();

int a[8][8];

struct piece{
	int x = 0;
	int y = 0;
};

int main(){
	
	int x, y, i = 1;
	
	while(1){
		print_map();
		cout << endl << "请输入横纵坐标x、y（棋子的位置）" << endl;
		cin >> x >> y;
		a[x][y] = 1;
		
		if(i == 1){
			if(x == 1)	a[x + 1][y] = 2;
			else if(x == 7)	a[x - 1][y] = 2;
			else if(y == 1)	a[x][y + 1] = 2;
			else if(y == 7)	a[x][y - 1] = 2;
			else	a[x][y + 1] = 2;
			cls();
			continue;
		}
		
		check();
		if(five_piece() == 1){
			cls();
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<"		";
			cout << "You win!" << endl;
			cls();
			print_map();
			break; 
		}else if(five_piece() == 2){
			cls();
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<"		";
			cout << "You lose!" << endl;
			cls();
			print_map();
			break;
		}
		
		cls();
		i++;
	}
	
	return 0;
}

void print_map(){
	for(int i = 1; i <= 7; i++){
		cout << "  " << i;
	}
	
	cout << endl;
	
	for(int i = 1; i <= 7; i++){
		cout << i << " "; 
		for(int j = 1; j <= 7; j++){
			if(a[i][j] == 1){
				if(j == 7)	cout << "●";//■
				else	cout << "●-";
				continue;
			}
			
			if(a[i][j] == 2){
				if(j == 7)	cout << "■";//●
				else	cout << "■-";
				continue;
			}
			
			if(j == 7){
				cout<<"+";
				continue;
			}
			cout<<"+--";
		} 
		if(i == 7)	continue;
		cout << endl << "  |  |  |  |  |  |  |";
		cout << endl;
	}
}

void check(){
	piece me[64];
	piece you[64];
	
	int n,m;
	n = m = 1;
	
	for(int i = 1;i <= 7; i++){
		for(int j = 1; j <= 7; j++){
			if(a[i][j] == 1){
				me[n].x = i;
				me[n].y = j;
				n++;
			}else if(a[i][j] == 2){
				you[n].x = i;
				you[n].y = j;
				m++;
			}
		}
	}
	
}

int five_piece(){
	for(int i = 1; i <= 7; i++){
		for(int j = 1; j <= 3; j++){
			if(a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2]&&
			 a[i][j + 2] == a[i][j + 3] && a[i][j + 3] == a[i][j + 4]&&a[i][j + 4] == a[i][j + 5]){
			 	if(i == 1)	return 1;
			 	if(i == 2)	return 2;
			 }
		}
	}
}

void cls(){
	Sleep(3000);
	system("cls");
}
