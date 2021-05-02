#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#define defult_color system("color 0F")
#define cls system("cls")
using namespace std;

void print_heart();

int main(){
	
	system("color 04"); //f0
	print_heart();
	
	return 0;
}

void print_heart(){
	cout << "      ***     ***" << endl;
	cout << "     *520*   *520*" << endl;
	cout << "    ******* *******" << endl;
	cout << "   *****Teacher*****" << endl;
	cout << "   ******Thank******" << endl;
	cout << "    ******you******" << endl;
	cout << "     ******I******" << endl;
	cout << "      ***LOVE!***" << endl;
	cout << "       ***YOU***" << endl;
	cout << "        *******" << endl;
	cout << "         *****" << endl;
	cout << "          ***" << endl;
}
