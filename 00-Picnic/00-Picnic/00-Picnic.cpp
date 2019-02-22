// 00-Picnic.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <list>
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

int calculate(const bool are_friends[][10], list<int> &students, int total_num) {
	int ret;
	ret = 0;

	// 모든 학생들에 대해 짝을 구하게 되면 1을 리턴하고 종료
	if (students.size() == 0) {
		cout << "~~~1을 리턴" << endl;
		return 1;
	}
	
	// 파라미터로 받은 학생들 중 첫번째 학생을 우선 고름
	int first_target;
	first_target = students.front();

	// 이전에 선택된 적이 없는 학생들 중에서 첫번째 짝을 고름
	int first_target_pair;
	list<int> list_sub;
	bool flag;
	flag = false;

	for (int j = first_target + 1; j < total_num; j++) {
		if (are_friends[first_target][j]) {
			flag = true;
			first_target_pair = j;

			// 한쌍을 찾은 경우, 다시 또 다른 쌍을 찾기 위해 선택된 사람들을 제외하고 다시 학생들 list를 구성함
			list_sub = make_list_sub(first_target, first_target_pair, students);

			// 남은 학생들에 대해 짝을 고를 수 있는지 재귀적으로 확인함
			ret += calculate(are_friends, list_sub, total_num);
		}
	}

	if (flag == false) {
		// 짝을 아예 찾지 못하는 경우 0을 리턴하고 종료
		return 0;
	} 

	return ret;
}

int ncases(const bool are_friends[][10], list<int> &whole_students) {
	int ret;
	ret = 0;
	
	ret = calculate(are_friends, whole_students, whole_students.size());
	
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
		cout << ncases(are_friends, whole_students) << endl;
	}
	
	system("pause");
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
