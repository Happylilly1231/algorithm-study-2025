/*
    알고리즘 : 이분탐색
    시간복잡도 : O(NlogN)
    아이디어 : 재귀를 이용한 이분탐색 - 백준 제출 시 2412KB, 44ms
              (반복문, C++ STL binary_search()를 이용한 이분탐색 제출 시 2412KB, 48ms)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<int> &arr, int low, int high, int target)
{
    if (low > high)
        return false;

    int mid = (low + high) / 2;

    if (target == arr[mid])
        return true;
    if (target < arr[mid])
        return binary_search(arr, low, mid - 1, target);
    else
        return binary_search(arr, mid + 1, high, target);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a;

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        cout << binary_search(arr, 0, n - 1, a) << '\n';
    }

    return 0;
}