/*
    알고리즘 : 그리디 알고리즘
    시간 복잡도 : O(N)
    아이디어 : 동전을 최소로 사용하려면 큰 액수 동전을 최대한 많이 사용해야 함
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, cnt = 0;
    int a[11];

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        int j = k / a[i];
        k -= j * a[i];
        cnt += j;
    }

    cout << cnt;

    return 0;
}