// 00-picnic-book-solution.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int ncases(const bool are_friends[][10], int num_friends, bool taken[10]) {
	int first_free = -1;
	for (int i = 0; i < num_friends; i++) {
		if (!taken[i]) {
			first_free = i;
			break;
		}
	}

	if (first_free == -1) {
		return 1;
	}

	int ret = 0;
	for (int pair_with = first_free + 1; pair_with < num_friends; pair_with++) {
		if (!taken[pair_with] && are_friends[first_free][pair_with]) {
			taken[first_free] = true;
			taken[pair_with] = true;
			ret += ncases(are_friends, num_friends, taken);

			taken[first_free] = false;
			taken[pair_with] = false;
		}
	}
	return ret;
}

int main()
{
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int nfriends, npairs;
		cin >> nfriends >> npairs;
		bool are_friends[10][10] = { false };
		bool taken[10] = { false };

		for (int j = 0; j < npairs; j++) {
			int a, b;
			cin >> a >> b;
			are_friends[a][b] = true;
			are_friends[b][a] = true;
		}
		cout << ncases(are_friends, nfriends, taken) << endl;
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
