#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[120][30000];

void local(int);

int main(){
	
	int url;
	cout << "Please input a number,it probabaly less than 3.\n";
	cout << "This program will help you to print or count paska trangle.\n";
	cout << "If you input 0,program will help you to count (x,y).\n";
	cout << "Else if you input 1,program will print a number paska trangle.\n";
	cout << "Else if you input 2,program will print a character paska trangle.\n";
	
	int cnt = 0;
	
	while(1)
	{
		cout << endl << endl;
		cout << "Your number is: \n";
		cin >> url;
		
		if(url < 0)
		{
			cout << "--------------Program ended--------------" << endl;
			break;
		}
		
		if(url == 0)
		{
			cout << "Input two numbers that smaller than 120: \n";
			
			int x,y;
			cin >> x >> y;
			cout << a[x][y];
		}
		else if(url == 1)
		{
			cout << "Input one number that smaller than 35: \n";
			
			int n;
			cin >> n;
			
			local(n);
			
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= i; j++)
				{
					cout << a[i][j] << "	";
				}
				cout << endl;
			}
		}
		else if(url == 2)
		{
			cout << "Input one number that smaller than 40: \n";
			
			int n;
			cin >> n;
			
			local(n);
			
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= i; j++)
				{
					if(a[i][j] % 2)
					{
						cout << "* ";
					}else{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else
		{
			if(cnt == 2)
			{
				cout << "You wrong so many times,so program is died!\n";
				break;
			}
			else
			{
				cnt++;
				cout << "You only have " << 3-cnt << " wrong times!\n";
			}
		}
	}
	
	return 0;
}

void local(int n)
{
	a[1][1] = 1;
	a[2][1] = a[2][2] = 1;
	
	for(int i = 3; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
}
