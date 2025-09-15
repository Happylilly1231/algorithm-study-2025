/*
    알고리즘 : 이분탐색
    시간복잡도 : O(Klog(maxN))
    아이디어 : low를 1, high를 가장 긴 랜선 길이로 선언한 후
              mid 길이로 잘랐을 때 총 몇 개의 랜선을 만들 수 있는지 계산하여
              만들 수 있는 최대 랜선의 길이를 구함
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    unsigned int maxn = 0;

    cin >> k >> n;

    unsigned int lan[k];
    for (int i = 0; i < k; i++)
    {
        cin >> lan[i];
        maxn = max(maxn, lan[i]);
    }

    unsigned int low = 1, high = maxn, mid, sum, ans = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += lan[i] / mid;
        }
        if (sum >= n)
        {
            low = mid + 1;
            ans = max(ans, mid);
        }
        else
            high = mid - 1;
    }

    cout << ans;

    return 0;
}