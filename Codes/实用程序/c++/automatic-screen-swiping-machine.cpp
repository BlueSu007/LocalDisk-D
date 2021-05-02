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
	cout << "请输入你想刷屏的遍数" << endl;
	cin >> a;
	cout << "请输入间隔的秒数" << endl;
	cin >> b;
	b *= 1000;
	cout << "请复制你想刷屏的内容" << endl;
	system ( "pause" );
	cout << "请把鼠标移动到聊天框" << endl;
	Sleep(2000);
	cout << "刷屏将在3秒后开始" << endl;
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
	cout << "刷屏结束" << endl;
}
//我谔谔 
