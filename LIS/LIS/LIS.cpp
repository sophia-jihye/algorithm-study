#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring> //memset

using namespace std;

int num;
int cache[100];
int nums[100];


int solve_2(int start) {
	// memoization
	int &result = cache[start];
	if (result == -1) {
		result = 1;
		for (int next = start + 1; next < num; next++) {
			if (nums[start] < nums[next]) {
				result = max(result, 1+solve_2(next));
			}
		}

	}
	return result;
}

int main(void) {
	int test_case;
	cin >> test_case;

	if (test_case < 0 || test_case>50)
		exit(-1);

	for (int i = 0; i < test_case; i++) {
		memset(cache, -1, sizeof(cache)); //캐시 초기화

		cin >> num;
		if (num < 0 || num>500)
			exit(-1);

		for (int i = 0; i < num; i++) {
			cin >> nums[i];
			if (nums[i] < 1 || nums[i]>100000)
				exit(-1);
		}

		cout << solve_2(0) << endl;
	}
	return 0;
}

