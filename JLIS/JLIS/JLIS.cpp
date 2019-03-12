#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num1, num2;
int propose_nums[200];
const long long NEGINF = numeric_limits<long long>::min();

int getLisSize(vector<int> seq, int maxValue) {
	if (seq.empty()) {
		return 0;
	}

	int first = seq.front();
	seq.erase(seq.begin());
	if (first > maxValue) {
		return getLisSize(seq, first) + 1;
	}

	return getLisSize(seq, maxValue);
}

int getLisSize(vector<int> seq) {
	return getLisSize(seq, NEGINF);
}

int solve(vector<int> nums1, vector<int> nums2) {
	

	vector<int> temp_nums1 = nums1;
	vector<int> temp_nums2 = nums2;

	// de-duplication
	for (int i = 0; i < temp_nums1.size(); i++) {
		bool is_duplicated = false;

		for (int j = 0; j < num2; j++) {
			if (temp_nums1[i] == nums2[j]) {
				is_duplicated = true;
				temp_nums1.erase(temp_nums1.begin() + i);
				i--;
				break;
			}
		}
	}

	// de-duplication
	for (int i = 0; i < temp_nums2.size(); i++) {
		bool is_duplicated = false;

		for (int j = 0; j < num1; j++) {
			if (temp_nums2[i] == nums1[j]) {
				is_duplicated = true;
				temp_nums2.erase(temp_nums2.begin() + i);
				i--;
				break;
			}
		}
	}

	return max(getLisSize(temp_nums1) + getLisSize(nums2), getLisSize(nums1) + getLisSize(temp_nums2));
}
int main(void) {
	int test_case;
	cin >> test_case;

	if (test_case < 0 || test_case>50)
		exit(-1);

	for (int i = 0; i < test_case; i++) {
		cin >> num1;
		cin >> num2;
		if (num1 < 0 || num1>100)
			exit(-1);
		if (num2 < 0 || num2>100)
			exit(-1);

		vector<int> nums1(num1+1);
		vector<int> nums2(num2+1);
		for (int i = 0; i < num1; i++) {
			cin >> nums1[i];
		}
		for (int i = 0; i < num2; i++) {
			cin >> nums2[i];
		}

		cout << solve(nums1, nums2) << endl;
	}
	return 0;
}

