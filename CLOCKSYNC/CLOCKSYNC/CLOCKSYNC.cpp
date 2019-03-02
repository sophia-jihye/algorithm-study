
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 9999
#define BTN_SIZE 10
#define CLOCK_SIZE 16

//linked[i][j]=1 i번 스위치와 j번 시계가 연결되어 있다
//linked[i][j]=0 i번 스위치와 j번 시계가 연결되어 있지 않다
int linked[BTN_SIZE][CLOCK_SIZE] = {
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

bool all_twelve(const vector<int> &clocks) {
	for (int i = 0; i < CLOCK_SIZE; i++) {
		if (clocks[i] != 12) {
			return false;
		}
	}
	return true;
}

vector<int> push_btn(vector<int> &clocks, int btn) {
	for (int i = 0; i < CLOCK_SIZE; i++) {
		if (linked[btn][i]) {
			if (clocks[i] == 12) {
				clocks[i] = 3;
			}
			else {
				clocks[i] += 3;
			}
		}
	}
	return clocks;
}

int solve(vector<int> &clocks, int btn){
	int result = INF;
	
	// Check if all clocks are aligned towards 12'
	if (btn == BTN_SIZE) {
		if (all_twelve(clocks)) {
			return 0;
		}
		else {
			return INF;
		}
	}

	// If you push the button 4 times, it turns back to the original state. 
	// It is like making a limitation that you can only push the button until 3 times.
	for (int cnt = 0; cnt < 4; cnt++) {
		result = min(result, cnt + solve(clocks, btn+1));

		// After pushing the button, states of the clocks are changed and the cnt becomes cnt+1 at the next loop.
		clocks = push_btn(clocks, btn);
	}

	return result;
}

int main(void) {
	int test_case;
	vector<int> clocks(CLOCK_SIZE);
	cin >> test_case;

	if (test_case < 0 || test_case>30) {
		exit(-1);
	}

	for (int i = 0; i < test_case; i++) {
		for (int j = 0; j < CLOCK_SIZE; j++) {
			cin >> clocks[j];
		}

		int result = solve(clocks, 0);
		if (result == INF) {
			cout << -1 << endl;
		}
		else {
			cout << result << endl;
		}
	}
	return 0;
}


