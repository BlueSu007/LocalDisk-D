#include <iostream>
using namespace std;

int main(){
	
	int mi=0, ac=0, r=0, bt=0, dh=0, a, b;
	cout << "端午节快乐！" << endl;
	cout << "去哪儿？？" << endl;
	cout << "1.制作工坊 2.仓库 3.商店" << endl;
	cin >> a;
	
	if (a==1){
		
		cout << "欢迎来到制作工坊，请问你要做：" << endl;
		cout << "1.蛋黄粽子 2.白棕子 3.肉粽子" << endl;
		cin >> b;
		
		if (b==1){
			cout << "你需要1份米，1份蛋黄，1片粽叶。" << endl;
			if(mi>=1 && dh>=1 && ac>=1){
				cout << "制作成功" ;
				mi-=0;
				dh-=0;
				ac-=0;
			}
			else
				cout << "材料不够！" ;
		}
		
		if (b==2){
			cout << "你需要1份米，1份白糖，1片粽叶。" << endl;
			if(mi>=1 && bt>=1 && ac>=1){
				cout << "制作成功" ;
				mi-=0;
				bt-=0;
				ac-=0;
			}
			else
				cout << "材料不够！" ;
		}
		
		if (b==3){
			cout << "你需要1份米，1块肉，1片粽叶。" << endl;
			if(mi>=1 && r>=1 && ac>=1){
				cout << "制作成功" ;
				mi-=0;
				r-=0;
				ac-=0;
			}
			else
				cout << "材料不够！" ;
		}
	}
	
	if (a==2){
		cout << "米" << " " << "白糖" << " " << "肉" << " " << "粽叶" << " " << "蛋黄" << endl;
		cout << mi << " " << " " << bt << " " << " " << r << " " << " " << ac << " " << " " << dh << endl;
	}
	
	return 0;
}
