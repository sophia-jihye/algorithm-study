#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

int board[100][100];
int cache[100][100];

bool solve(int y, int x, int max_size){

	// Return true if the state is at the targe point.
	if (y == max_size - 1 && x == max_size - 1) {
		return true;
	}

	// Return false if the state is out of the board.
	if (y >= max_size || x >= max_size) {
		return false;
	}

	int step = board[y][x];

	// result is a reference data for cache. 
	// When result changes, cache value also changes.
	// So you don't have to replace the values of cache each time.
	int &result = cache[y][x];
	if (result == -1) {
		result = solve(y + step, x, max_size) || solve(y, x + step, max_size);
	}
	return result;
}



int main(void){

	int test_case, max_size;
	cin >> test_case;

	if (test_case < 0 || test_case>50) {
		exit(-1);
	}

	for (int i = 0; i < test_case; i++){
		cin >> max_size;

		if (max_size < 2 || max_size>100)
			exit(-1);

		memset(cache, -1, sizeof(cache));

		// board[y][x] 
		for (int j = 0; j < max_size; j++) {
			for (int k = 0; k < max_size; k++) {
				cin >> board[j][k];
			}
		}

		if (solve(0, 0, max_size) == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}