/*
알고리즘: 그리디
시간 복잡도: O(N^2)
참고 링크: x
아이디어:
    - 최적의 해는 인출 시간이 적은 순으로 돈을 인출하는 것이다. 따라서 입력받은 벡터 P를 오름차순으로 정렬한 뒤, 앞부터 계산한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, x, cnt = 0;
    vector<int> P;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        P.push_back(x);
    }

    sort(P.begin(), P.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cnt += P[j];
        }
    }

    cout << cnt;

    return 0;
}