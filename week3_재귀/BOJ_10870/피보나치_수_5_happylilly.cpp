/*
알고리즘: 재귀
시간 복잡도: O(2^N)
참고 링크: x
아이디어: 재귀 함수를 이용하여 F(n) = F(n-1) + F(n-2)을 구현한다.
*/

#include <iostream>

using namespace std;

// 피보나치 함수
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    cout << fibonacci(n);

    return 0;
}