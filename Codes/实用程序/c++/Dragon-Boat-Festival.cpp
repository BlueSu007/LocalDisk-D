#include <iostream>
using namespace std;

int main(){
	
	int mi=0, ac=0, r=0, bt=0, dh=0, a, b;
	cout << "����ڿ��֣�" << endl;
	cout << "ȥ�Ķ�����" << endl;
	cout << "1.�������� 2.�ֿ� 3.�̵�" << endl;
	cin >> a;
	
	if (a==1){
		
		cout << "��ӭ��������������������Ҫ����" << endl;
		cout << "1.�������� 2.������ 3.������" << endl;
		cin >> b;
		
		if (b==1){
			cout << "����Ҫ1���ף�1�ݵ��ƣ�1Ƭ��Ҷ��" << endl;
			if(mi>=1 && dh>=1 && ac>=1){
				cout << "�����ɹ�" ;
				mi-=0;
				dh-=0;
				ac-=0;
			}
			else
				cout << "���ϲ�����" ;
		}
		
		if (b==2){
			cout << "����Ҫ1���ף�1�ݰ��ǣ�1Ƭ��Ҷ��" << endl;
			if(mi>=1 && bt>=1 && ac>=1){
				cout << "�����ɹ�" ;
				mi-=0;
				bt-=0;
				ac-=0;
			}
			else
				cout << "���ϲ�����" ;
		}
		
		if (b==3){
			cout << "����Ҫ1���ף�1���⣬1Ƭ��Ҷ��" << endl;
			if(mi>=1 && r>=1 && ac>=1){
				cout << "�����ɹ�" ;
				mi-=0;
				r-=0;
				ac-=0;
			}
			else
				cout << "���ϲ�����" ;
		}
	}
	
	if (a==2){
		cout << "��" << " " << "����" << " " << "��" << " " << "��Ҷ" << " " << "����" << endl;
		cout << mi << " " << " " << bt << " " << " " << r << " " << " " << ac << " " << " " << dh << endl;
	}
	
	return 0;
}
