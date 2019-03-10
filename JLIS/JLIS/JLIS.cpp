#include "pch.h"
#include <iostream>
#include <vector>
//#include <set>

using namespace std;

int solve(vector<int> &nums1, vector<int> &nums2) {
	/*set<int> result_set;
	for (int i = 0; i < nums1.size(); i++) {
		result_set.insert(nums1[i]);
	}
	for (int i = 0; i < nums2.size(); i++) {
		result_set.insert(nums2[i]);
	}
	return result_set.size();*/
}

int main(void) {
	int test_case, num1, num2;
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
		vector<int> nums1(num1, 0);
		vector<int> nums2(num2, 0);
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

