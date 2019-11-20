/*
	https://leetcode.com/problems/surrounded-regions/
	https://github.com/grandyang/leetcode/issues/130

	DFS method: lan vung 'O' tu bien bang DFS, tat ca vung lan den duoc danh dau '$'
	Nhung vung 'o" khong lan toi duoc la surrounded region.
	Gan lai cac vung gia tri 'O' thanh 'X', vung gia tri '$' thanh 'O'.

*/
#include <vector>
#include <cstdio>
using namespace std;

class solution {
public:
	void solve(vector<vector<char>>& board) {
		int n = board.size(), m= board[0].size(); // n hang, m cot
		printf("%d %d\n",n,m);
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (i==0 || i== n-1 || j==0 || j==m-1)  {
					boardDFS(board, i,j);
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

	void boardDFS(vector<vector<char>>& board, int i, int j) {
		int n = board.size(), m= board[0].size();
		if (board[i][j] == 'O') {
			board[i][j] = '$';
			if (j>0 && board[i][j-1] == 'O') boardDFS(board,i,j-1);
			if (j<m -1 && board[i][j+1] == 'O') boardDFS(board,i,j+1);
			if (i>0 && board[i-1][j] == 'O') boardDFS(board,i-1,j);
			if (i<n-1 && board[i+1][j] == 'O') boardDFS(board,i+1,j);
		}
	}
};

int main() {
	vector<vector<char>> board = {
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','O','O','X'},
		{'X','O','X','X'},
		{'X','O','X','X'}
	};
	solution anw;
	anw.solve(board);

	return 0;
}