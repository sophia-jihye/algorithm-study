#include "pch.h"
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

list<int> make_list_sub(int pair1, int pair2, list<int> whole_students) {
	list<int> list_sub;
	for (int item : whole_students) {
		if (item != pair1 && item != pair2) {
			list_sub.push_back(item);
		}
	}
	return list_sub;
}

int calculate(const bool are_friends[][10], list<int> students, int total_num) {

	// 모든 학생들에 대해 짝을 구하게 되면 1을 리턴하고 종료
	if (students.size() == 0) {
		return 1;
	}
	
	int ret = 0;

	// 파라미터로 받은 학생들 중 첫번째 학생을 우선 고름
	int first_target;
	first_target = students.front();

	// 이전에 선택된 적이 없는 학생들 중에서 첫번째 짝을 고름
	int first_target_pair;
	list<int> list_sub;

	for (int j = first_target + 1; j < total_num; j++) {
		list<int>::iterator it = find(students.begin(), students.end(), j);
		if (it != students.end() && are_friends[first_target][j]) {
			first_target_pair = j;

			// 한쌍을 찾은 경우, 다시 또 다른 쌍을 찾기 위해 선택된 사람들을 제외하고 다시 학생들 list를 구성함
			list_sub = make_list_sub(first_target, first_target_pair, students);

			// 남은 학생들에 대해 짝을 고를 수 있는지 재귀적으로 확인함
			ret += calculate(are_friends, list_sub, total_num);
		}
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int nfriends, npairs;
		cin >> nfriends >> npairs;
		bool are_friends[10][10] = { false };
		list<int> whole_students;
		for (int j = 0; j < nfriends; j++) {
			whole_students.push_back(j);
		}
		for (int j = 0; j < npairs; j++) {
			int a, b;
			cin >> a >> b;
			are_friends[a][b] = true;
			are_friends[b][a] = true;
		}
		cout << calculate(are_friends, whole_students, whole_students.size()) << endl;
	}
	
	return 0;
}

