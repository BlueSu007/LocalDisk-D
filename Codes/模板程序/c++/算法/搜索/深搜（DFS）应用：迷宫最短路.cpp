#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int r, c;
int minn = 0x7ffff;
int a[40 + 5][40 + 5], vis[40 + 5][40 + 5];
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
char tmp;

void dfs(int x, int y, int step);

int main(){
	
	cin >> r >> c;
	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cin >> tmp;
			if(tmp == '.')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}
	
	dfs(1, 1, 0);
	
	cout << minn + 1 << endl;
	
	return 0;
}

void dfs(int x, int y, int step){
	if(x == r && y == c){
		minn = step < minn ? step : minn;
		return ;
	}
	
	for(int i = 0; i < 4; i++){
		int fx = dx[i] + x;
		int fy = dy[i] + y;
		
		if(fx >= 1 && fy >= 1 && fx <= r && fy <= c && !vis[fx][fy] && !a[fx][fy]){
			vis[fx][fy] = 1;
			dfs(fx, fy, step + 1);
			vis[fx][fy] = 0;
		}
	}
}

/*
5 5
..###
#....
#.#.#
#.#.#
#.#..
*/
