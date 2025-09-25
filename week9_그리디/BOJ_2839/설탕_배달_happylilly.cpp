/*
알고리즘: 그리디
시간 복잡도: O(N)
참고 링크: x
아이디어:
    - 최적의 해는 5킬로그램 봉지를 최대한 많이 사용하는 것이다. 사용할 수 있는 5킬로그램 최대 봉지 수에서 1씩 줄이면서 나머지가 3으로 나누어지는지 확인한다.
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, n;

    cin >> N;

    int i = N / 5;
    int j;
    while (i >= 0)
    {
        n = N;
        n -= 5 * i;
        j = n / 3;
        n %= 3;
        if (n == 0)
            break;
        i--;
    }

    if (i >= 0)
        cout << i + j;
    else
        cout << -1;

    return 0;
}