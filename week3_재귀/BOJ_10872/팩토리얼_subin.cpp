/*
    알고리즘 : 재귀
    시간복잡도 : O(n)
    아이디어 : n을 입력받아 n, n-1, ..., 1 순서로 곱해 n!을 구함
*/

#include <iostream>

using namespace std;

int factorial_num = 1;

void factorial(int n)
{
    if (n == 0)
    {
        return;
    }
    factorial_num *= n--;
    factorial(n);
}

int main()
{
    int n;

    cin >> n;

    factorial(n);
    cout << factorial_num;

    return 0;
}