#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[50 + 5][50 + 5], q[55 * 55][3 + 1];
char tmp;
int n, m, head, tail;
const int bx[4] = {0, 0, -1, 1};
const int by[4] = {-1, 1, 0, 0};

bool bfs();

int main(){
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> tmp;
			if(tmp == '.')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}
	
	if(bfs())
		cout << q[tail - 1][3] + 1 << endl;
	else
		cout << -1 << endl;
	
	return 0;
} 

bool bfs(){
	q[1][1] = 1;
	q[1][2] = 1;
	q[1][3] = 0;
	
	a[1][1] = 1;
	head = tail = 1;
	tail++;
	
	while(head < tail){
		for(int k = 0; k < 4; k++){
			int fx = bx[k] + q[head][1];
			int fy = by[k] + q[head][2];
			
			if(fx >= 1 && fy >= 1 && fx <= n && fy <= m && !a[fx][fy]){
				q[tail][1] = fx;
				q[tail][2] = fy;
				q[tail][3] = q[head][3] + 1;
				
				tail++;
				a[fx][fy] = 1;
			}
			
			if(fx == n && fy == m)
				return 1;
		}
		
		head++;
	}
	
	return 0;
}
/*
5 5
..###
#....
#.#.#
#.#.#
#.#..
*/ 
