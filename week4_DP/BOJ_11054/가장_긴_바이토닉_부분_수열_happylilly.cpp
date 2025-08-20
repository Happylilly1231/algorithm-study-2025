/*
알고리즘: DP
시간 복잡도: O(NlogN)
참고 링크: x
아이디어:
    lis_dp -> LIS 이진 탐색 알고리즘 순방향
    lds_dp -> LIS 이진 탐색 알고리즘 역방향
    이진 탐색이므로 길이를 저장해놔야 함 -> len 배열에 합쳐서 저장
    len 배열에서 가장 큰 값이 가장 긴 바이토닉 수열의 길이
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n + 1);
    vector<int> lis_dp;
    vector<int> lds_dp;
    vector<int> len(n + 1);

    arr[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        // 비어있거나 dp의 마지막 원소보다 here이 크다면 dp에 here을 추가
        if (lis_dp.empty() || lis_dp.back() < arr[i])
        {
            lis_dp.push_back(arr[i]);
        }
        else
        { // 그렇지 않다면 lower_bound를 찾아 dp 배열 갱신
            int lb = lower_bound(lis_dp.begin(), lis_dp.end(), arr[i]) - lis_dp.begin();
            lis_dp[lb] = arr[i];
        }

        len[i] = lis_dp.size();
    }

    for (int i = n; i >= 1; i--)
    {
        // 비어있거나 dp의 마지막 원소보다 here이 크다면 dp에 here을 추가
        if (lds_dp.empty() || lds_dp.back() < arr[i])
        {
            lds_dp.push_back(arr[i]);
        }
        else
        { // 그렇지 않다면 lower_bound를 찾아 dp 배열 갱신
            int lb = lower_bound(lds_dp.begin(), lds_dp.end(), arr[i]) - lds_dp.begin();
            lds_dp[lb] = arr[i];
        }

        len[i] += lds_dp.size();
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (len[i] > max)
        {
            max = len[i];
        }
    }

    cout << max - 1;

    return 0;
}