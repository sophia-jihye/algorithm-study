
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string solve(string::iterator &it) {
	char head1 = *it;

	// Finishes process if head contains only 'b' or 'w'.
	// Send next iterator only if head contains more characters to process.
	// So it is okay to implement it++ even when there is no iterator.
	it++;
	if (head1 == 'b' || head1 == 'w') {
		return string(1, head1);
	}

	string upperLeft = solve(it);	// 1
	string upperRight = solve(it);	// 2
	string lowerLeft = solve(it);	// 3
	string lowerRight = solve(it);	//4

	// Concatenate sub solutions with inversed order.
	// 1 2 3 4 -> 3 4 1 2
	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void)
{
	int test_case;
	cin >> test_case;

	if (test_case < 0 || test_case>50)
		exit(-1);

	string compressed_chars;
	for (int i = 0; i < test_case; i++) {
		cin >> compressed_chars;
		if (compressed_chars.size() > 1000)
			exit(-1);

		string::iterator it = compressed_chars.begin();

		cout << solve(it) << endl;
	}
	return 0;
}

