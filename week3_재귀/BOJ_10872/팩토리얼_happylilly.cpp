/*
알고리즘: 재귀
시간 복잡도: O(N)
참고 링크: x
아이디어: 재귀 함수를 이용하여 N부터 1까지 파고들며 재귀로 구한다.(0 팩토리얼은 1 반환)
*/

#include <iostream>

using namespace std;

// 팩토리얼 구하는 함수
int factorial(int N)
{
    if (N == 0 || N == 1)
        return 1;

    return factorial(N - 1) * N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    cout << factorial(N);

    return 0;
}