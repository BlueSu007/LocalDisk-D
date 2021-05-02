/*
function:
Input tree's preorder,(have NULL) out put tree's preorder/midorder/lastorder.(no NULL)
use pointer build tree.
Input:
a b c * * d * * e f * * *
output:
a b c d e f
c b d a f e
c d b f e a
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct tree{
	char date;
	tree *lchild, *rchild;
};

tree *createtree(){
	tree *t;
	char x;
	cin >> x;
	
	if(x == '*')
		return NULL;
		
	t = new tree;
	t -> date = x;
	t -> lchild = createtree();
	t -> rchild = createtree();
}

void preorder(tree *t);
void midorder(tree *t);
void lastorder(tree *t);

int main(){
	
	tree *head, *temp;
	char x;
	
	head = createtree();
	preorder(head);
	cout << endl;
	
	midorder(head);
	cout << endl;
	
	lastorder(head);
	cout << endl;
	
	return 0;
}

void preorder(tree *t){
	if(t != NULL){
		cout << t -> date << " ";
		preorder(t -> lchild);
		preorder(t -> rchild);
	}
}

void midorder(tree *t){
	if(t != NULL){
		midorder(t -> lchild);
		cout << t -> date << " ";
		midorder(t -> rchild);
	}
}

void lastorder(tree *t){
	if(t != NULL){
		lastorder(t -> lchild);
		lastorder(t -> rchild);
		cout << t -> date << " ";
	}
}
