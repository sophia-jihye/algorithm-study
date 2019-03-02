
#include "pch.h"
#include <iostream>

using namespace std;

int solve(int board[][20], int H, int W) {
	int result = 0;
	for (int i=0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == 0) {
				result++;
			}
		}
	}
	return result;
}

int main() {
	int test_case, H, W;
	int board[20][20];
	char is_black[20];

	cin >> test_case;
	if (test_case < 0 || test_case > 30) {
		exit(-1);
	}

	for (int i = 0; i < test_case; i++) {
		cin >> H >> W;

		if (H < 1 || H > 20 || W < 1 || W > 20) {
			exit(-1);
		}

		for (int i = 0; i < H; i++) {
			cin >> is_black;
			for (int j = 0; j < W; j++) {
				board[i][j] = (is_black[j] == '#') ? 1 : 0;
			}
		}

		cout << solve(board, H, W) << endl;
	}

	return 0;
}
