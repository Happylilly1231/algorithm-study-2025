/*
    알고리즘 : 이분탐색
    시간복잡도 : O(NlogN)
    아이디어 : 어떤 수 x가 주어졌을 때, x 이하의 숫자가 몇 개 있는지 계산
                각 행 i에서 x/i 이하의 숫자가 존재 -> min(x/i, n)개
              이 개수를 이용해 이분 탐색으로 k번째 수를 찾음
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;

    cin >> n;
    cin >> k;

    long long low = 1, high = n * n;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            cnt += min(mid / i, n);
        }

        if (cnt >= k)
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << low;
    return 0;
}