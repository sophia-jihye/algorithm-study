
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &fence, int left_idx, int right_idx) {
	
	// base case: only one fence
	if (left_idx == right_idx) {
		return fence[left_idx];
	}

	int mid_idx = (left_idx + right_idx) / 2;

	// divide whole part into 2 parts: left part, right part.
	// conquer each part recursively.
	// returns only one fence which is the biggest.
	int ret = max(solve(fence, left_idx, mid_idx), solve(fence, mid_idx + 1, right_idx));

	// let's find other cases.
	int lower_idx = mid_idx;
	int higher_idx = mid_idx + 1;

	// choose one fence, and then expand as below.
	int height = min(fence[lower_idx], fence[higher_idx]);
	
	// since we chose smaller fence, at least it has one bigger fence next to it.
	ret = max(ret, height * 2);

	while (left_idx < lower_idx || higher_idx < right_idx) {

		// go higher or lower. towrds bigger fence.
		if ((lower_idx == left_idx || fence[lower_idx - 1] < fence[higher_idx + 1]) && higher_idx < right_idx) {
			higher_idx++;
				height = min(height, fence[higher_idx]);
		}
		else {
			lower_idx--;
			height = min(height, fence[lower_idx]);
		}

		ret = max(ret, height*(higher_idx - lower_idx + 1));
	}

	return ret;
}

int main(void){
	int test_case, num;
	cin >> test_case;

	if (test_case < 0 || test_case > 50)
		exit(-1);

	for (int i = 0; i < test_case; i++){
		cin >> num;
		vector<int> fence(num, 0);

		for (int j = 0; j < num; j++){
			cin >> fence[j];
			if (fence[j] < 0 || fence[j]>20000)
				exit(-1);

		}

		cout << solve(fence, 0, fence.size()-1) << endl;
	}
	return 0;
}

