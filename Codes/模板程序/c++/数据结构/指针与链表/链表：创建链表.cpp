#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct node{
	int id;
	node *next;
}; 

int main() {
	
	int n;
	node *head = NULL, *tail = NULL;
	cin >> n;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		node *pointer = new node;
		cin >> pointer -> id;
		
		if ( head == NULL ) {
			head = pointer;
			tail = pointer;
		}
		else {
			tail -> next = pointer;
			tail = pointer;
		}
		
		tail -> next = NULL;
	}
	
	node *pointer = head;
	while ( pointer ) {
		cout << pointer -> id << " ";
		pointer = pointer -> next;
	}
	
	return 0;
}
/*
input:
5
1 2 3 4 5
output:
1 2 3 4 5
*/
