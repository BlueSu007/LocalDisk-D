#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[500 + 5][500 + 5], vis[500 + 5], q[500 + 5];
int n, m;
int head, tail;
void bfs();

int main(){
	
	cin >> m >> n;
	
	int x, y, z;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	
	bfs();
	
	for(int i = 1; i <= m; i++){
		cout << q[i] << " ";
	}
	
	return 0;
}

void bfs(){
	head = tail = 1;
	vis[1] = 1;
	q[tail++] = 1;
	
	while(head < tail){
		int cur = q[head++];
		for(int i = 1; i <= m; i++){
			if(!vis[i] && a[cur][i]){
				vis[i] = 1;
				q[tail++] = i;
			}
		}
	}
}

/*
5 6
1 2
1 3
1 5
2 4
3 5
4 5
*/
