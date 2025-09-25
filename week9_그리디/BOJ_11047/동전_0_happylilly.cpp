/*
알고리즘: 그리디
시간 복잡도: O(N)
참고 링크: x
아이디어:
    - 최적의 해는 값이 큰 동전을 먼저 최대로 사용하는 것이다. 따라서 입력받은 동전 벡터를 반대로 검사하며, 몫을 cnt에 더하고 나머지를 다음 작은 동전으로 나눠준다.
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, A[10], cnt = 0;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        cnt += K / A[i];
        K %= A[i];
        if (K == 0)
            break;
    }

    cout << cnt;

    return 0;
}