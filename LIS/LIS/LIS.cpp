#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

int num;
int nums[500];
int propose_nums[500];
int lis_len_idx;

// 분할 정복
void lis4(int val) {
	if (lis_len_idx == 0 || (lis_len_idx > 0 && propose_nums[lis_len_idx - 1] <= val)) {
		propose_nums[lis_len_idx] = val;
		lis_len_idx++;
		return;
	}

	int front = 0;
	int end_temp = lis_len_idx - 1;
	while (front <= end_temp) {
		int mid = (front + end_temp) / 2;
		if (propose_nums[mid] < val) 
			front = mid + 1;
		else 
			end_temp = mid - 1;
		
	}
	propose_nums[end_temp + 1] = val;
}

int main(void) {
	int test_case;
	cin >> test_case;

	if (test_case < 0 || test_case>50)
		exit(-1);

	for (int i = 0; i < test_case; i++) {
		// reset lis_len_idx
		lis_len_idx = 0;

		cin >> num;
		if (num < 0 || num>500)
			exit(-1);

		for (int i = 0; i < num; i++) {
			cin >> nums[i];
			if (nums[i] < 1 || nums[i]>100000)
				exit(-1);
		}

		for (int i = 0; i < num; i++) {
			lis4(nums[i]);
		}

		cout << lis_len_idx << endl;
	}
	return 0;
}

