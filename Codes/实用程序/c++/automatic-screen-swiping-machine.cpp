#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
using namespace std;

int main() {
	
	int a;
	double b;
	cout << "����������ˢ���ı���" << endl;
	cin >> a;
	cout << "��������������" << endl;
	cin >> b;
	b *= 1000;
	cout << "�븴������ˢ��������" << endl;
	system ( "pause" );
	cout << "�������ƶ��������" << endl;
	Sleep(2000);
	cout << "ˢ������3���ʼ" << endl;
	Sleep(1000);
	cout << "3" << endl;
	Sleep(1000);
	cout << "2" << endl;
	Sleep(1000);
	cout << "1" << endl;
	mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 );
	mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
	for ( int i = 0 ; i < a ; i++ ) {
	    keybd_event ( 0x11, 0, 0, 0 );
		keybd_event ( 0x56, 0, 0, 0 ); 
	    keybd_event ( 0x56, 0, 2, 0 ); 
	    keybd_event ( 0x11, 0, 2, 0 );
	    keybd_event ( VK_RETURN, 0, 0, 0 );
	    keybd_event ( VK_RETURN, 0, 2, 0 );
		Sleep(b);
	}
	cout << "ˢ������" << endl;
}
//������ 
