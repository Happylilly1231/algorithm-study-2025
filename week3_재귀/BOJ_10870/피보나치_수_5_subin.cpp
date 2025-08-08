/*
    알고리즘 : 재귀
    시간복잡도 : O(2^n)
    아이디어 : n을 입력받아 F(n) = F(n-1) + F(n-2)를 재귀로 구함
*/

#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    cin >> n;

    cout << fibonacci(n);

    return 0;
}