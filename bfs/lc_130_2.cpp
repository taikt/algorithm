/*
	https://leetcode.com/problems/surrounded-regions/
	https://github.com/grandyang/leetcode/issues/130

	BFS method: lan vung 'O' tu bien bang BFS, tat ca vung lan den duoc danh dau '$'
	Nhung vung 'o" khong lan toi duoc la surrounded region.
	Gan lai cac vung gia tri 'O' thanh 'X', vung gia tri '$' thanh 'O'.
	
	mapping 2D-array (m hang, n cot) vs 1D-array
	a[i][j] => i*m+j=t, i=[t/m], j=t%m
	a[i+1][j] => (i+1)*m +j = t+m
	a[i-1][j] => (i-1)*m +j = t-m
	a[i][j-1] => i*m+j - 1 = t-1
	a[i][j+1] => i*m+j +1 = t+1
*/
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

class solution {
public:
	void solve(vector<vector<char>>& board) {
		int n = board.size(), m= board[0].size(); // n hang, m cot
		printf("%d %d\n",n,m);
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (i==0 || i== n-1 || j==0 || j==m-1)  {
					if (board[i][j]=='O') boardBFS(board, i,j);
				}
			}
		}

		for (int i=0;i<n; i++) {
			for (int j=0; j<m; j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j]=='$') board[i][j] = 'O';
			}
		}

		//print output
		for (int i=0;i<n; i++) {
			for (int j=0; j<m; j++) {
				printf("%c ", board[i][j]);
			}
			printf("\n");
		}
	}

	void boardBFS(vector<vector<char>>& board, int i, int j) {
		int n = board.size(), m= board[0].size();
		int t;
		queue<int> q;
		q.push(i*m+j);
		board[i][j] = '$';
		
		while (!q.empty()) {
			t= q.front(); q.pop();
			int x=t/n, y=t%n;
			if (y>0 && board[x][y-1]=='O') {board[x][y-1]='$'; q.push(t-1);}
			if (y<n-1 && board[x][y+1]=='O') {board[x][y+1]='$'; q.push(t+1);}
			if (x>0 && board[x-1][y]=='O') {board[x-1][y]='$'; q.push(t-m);}
			if (x<n-1 && board[x+1][y]=='O') {board[x+1][y]='$'; q.push(t+m);}
		}
	}
};

int main() {
	vector<vector<char>> board = {
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','O','O','X'},
		{'X','O','X','X'},
		{'X','X','O','X'}
	};
	solution anw;
	anw.solve(board);

	return 0;
}