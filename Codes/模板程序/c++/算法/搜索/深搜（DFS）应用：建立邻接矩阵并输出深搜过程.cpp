#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int a[500 + 5][500 + 5], vis[500 + 5];

void dfs(int cur);

int main(){
	
	cin >> m >> n;
	
	int x, y, z;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			cout << a[i][j] << " ";
		}
		
		cout << endl;
	}
	
	cout << endl;
	vis[1] = 1;
	dfs(1);
	
	return 0;
}

void dfs(int cur){
	cout << cur << " ";
	
	for(int i = 1; i <= m; i++){
		if(!vis[i] && a[cur][i]){
			vis[i] = 1;
			dfs(i);
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
