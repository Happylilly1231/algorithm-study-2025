/*
알고리즘: 이분탐색
시간 복잡도: O(NlogN)
참고 링크:
    - 이분탐색
        - https://m42-orion.tistory.com/69
아이디어:
    - 구역을 계속 반으로 나누어 target이 있는 쪽을 찾아가는 이분탐색으로 검사한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, x;

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    // target 입력
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        bool isFound = binary_search(v.begin(), v.end(), x); // 이분 탐색
        if (isFound)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}