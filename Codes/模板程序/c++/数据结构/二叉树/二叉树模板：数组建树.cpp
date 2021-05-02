/*
function:
Input all tree:
6
a b c
b d i
c j *
d * *
i * *
j * *
(b is a's lchild, c is a's rchild)(* is NULL)
output all count:
a b d i c j
b d i a c j
b d i c j a
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

char a[505][4];

void preorder(char root);
void midorder(char root);
void lastorder(char root);

int main(){
	
	int n;
	cin >> n;
	
	char x,y,z;
	for(int i = 1; i <= n; i++){
		cin >> x >> y >> z;
		if(i == 1)	a[1][0] = x;
		a[x][1] = y;
		a[x][2] = z;
	}
	
	preorder(a[1][0]);
	cout << endl;
	
	midorder(a[1][0]);
	cout << endl;
	
	lastorder(a[1][0]);
	cout << endl;
	
	return 0;
} 

void preorder(char root){
	if(root != '*'){
		cout << root << " ";
		preorder(a[root][1]);
		preorder(a[root][2]);
	}
}

void midorder(char root){
	if(root != '*'){
		midorder(a[root][1]);
		cout << root << " ";
		midorder(a[root][2]);
	}
}

void lastorder(char root){
	if(root != '*'){
		lastorder(a[root][1]);
		lastorder(a[root][2]);
		cout << root << " ";
	}
}
/*
7
a b c
b d e
c * *
d * *
e f g
f * *
g * *
a b d e f g c
d b f e g a c
d f g e b c a
*/
