/*

두개의 정수 수열 A와 B에서 각각 길이 0 이상의 증가 부분 수열을 얻은 뒤

이들을 크기 순서대로 합친 것을 합친 증가 부분 수열이라고 부른다.

이 중 가장 긴 수열을 합친 LIS(Joined LIS)라고 부른다.

JLIS의 길이를 구하시오

*/

#include "pch.h"
#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;



//입력이 32비트 부호 있는 정수의 모든 값을 가질 수 있으므로

//인위적인 최소치는 64비트여야한다.

const long long NEGINF = numeric_limits<long long>::min();

int A[100], B[100];

int cache[101][101]; //aIdx, bIdx가 -1부터 시작하므로 100+1

int A_size, B_size;



//min(A[aIdx], B[bIdx]), max(A[aIdx], B[bIdx])로 시작하는

//합친 증가 부분 수열의 최대 길이를 반환

//단 aIdx==bIdx==-1 혹은 A[aIdx]!=B[bIdx]라고 가정

int jlis(int aIdx, int bIdx)

{

	//메모이제이션

	int &result = cache[aIdx + 1][bIdx + 1];

	if (result != -1)

		return result;



	result = 0;

	long long a = (aIdx == -1 ? NEGINF : A[aIdx]);

	long long b = (bIdx == -1 ? NEGINF : B[bIdx]);

	long long maxElement = max(a, b);

	//다음 원소를 찾는다

	for (int nextA = aIdx + 1; nextA < A_size; nextA++)

		if (maxElement < A[nextA])

			result = max(result, jlis(nextA, bIdx) + 1);

	for (int nextB = bIdx + 1; nextB < B_size; nextB++)

		if (maxElement < B[nextB])

			result = max(result, jlis(aIdx, nextB) + 1);

	return result;

}



int main(void)

{

	int test_case;

	cin >> test_case;

	if (test_case < 0 || test_case>50)

		exit(-1);



	for (int i = 0; i < test_case; i++)

	{

		memset(cache, -1, sizeof(cache));

		cin >> A_size >> B_size;

		if (A_size > 100 || B_size > 100 || A_size < 1 || B_size < 1)

			exit(-1);

		for (int j = 0; j < A_size; j++)

			cin >> A[j];

		for (int j = 0; j < B_size; j++)

			cin >> B[j];

		cout << jlis(-1, -1) << endl << endl;

	}

	return 0;

}