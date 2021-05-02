#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <cstring>
using namespace std;

int a1[1000], b1[1000], c[1002];

int main(){
	
	char a[1000], b[1000];
	cin >> a >> b;
	
	int la, lb, i;
	la = strlen(a); 
	lb = strlen(b);
	
	for(i = 0; i <= la - 1; i++)
		a1[i] = a[la - 1 - i] - 48;
	for(i = 0; i <= lb - 1; i++)
		b1[i] = b[lb - 1 - i] - 48;
		
	for(i = 0; i <= 999; i++)
		c[i] = a1[i] + b1[i];
		
	for(i = 0; i <= 999; i++)
		if(c[i] < 0){
			c[i + 1]--;
			c[i] = c[i] + 10;
		}
		
	i = 1001;
	
	while(c[i] == 0 && i > 0)
		i--;
		
	for(; i >= 0; i--)
		cout << c[i];
		
	return 0;
}

