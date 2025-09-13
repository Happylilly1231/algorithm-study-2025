/*
알고리즘: 이분탐색
시간 복잡도: O(NlogN)
참고 링크:
    - 이분탐색
        - https://m42-orion.tistory.com/69
    - lower bound
        - https://yoongrammer.tistory.com/105
아이디어:
    - B[k]를 직접적으로 찾을 수 없음(시간 초과)
    => B[k] 대신 B[k]의 lower bound 찾기(이 문제에서 B[k] 반드시 존재하므로 B[k]의 lower bound = B[k])
        - mid가 B[k] 이상 값 -> 왼쪽 부분(mid까지 포함(현재 mid가 B[k]의 lower bound일 수 있으므로)) 탐색
        - mid가 B[k] 미만 값 -> 오른쪽 부분(mid + 1) 탐색
        - 탐색 종료(low == high) 후 low(=high)가 B[k]의 lower bound, 즉 B[k]가 됨
        - 문제점: B[k]를 모르므로 B[k]로 직접 비교할 수 X
            - B[k] = k번째로 작은 값
            - mid 이하 값 개수 cnt가 k 이상 -> mid는 B[k] 이상 값
            - mid 이하 값 개수 cnt가 k 미만 -> mid는 B[k] 미만 값
            => 해결: 따라서 mid와 B[k] 대신 cnt와 k를 비교하여 탐색
*/

#include <iostream>

using namespace std;

long long N, k;

// 이분 탐색
void binarySearch()
{
    long long low = 1, high = N * N;
    long long mid;

    while (low < high) // 같을 때 탐색 종료
    {
        mid = (low + high) / 2;

        // mid 이하 값 개수 cnt 구하기
        long long cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            // 현재 열에서 mid 이하 값 개수 -> mid / i (ex. 8/1=8, 8/2=4, 8/3=2, 8/4=2)
            if (mid / i >= N) // 해당 개수가 N개 이상이면 N까지만 더해야 함
                cnt += N;
            else
                cnt += mid / i;
        }

        // 현재 mid가 B[k] 이상인지 미만인지 판단 후 탐색 범위 갱신
        if (cnt >= k) // cnt가 k 이상 -> 현재 mid가 B[k] 이상 값임
        {
            high = mid; // 왼쪽 부분(mid까지 포함) 탐색
        }
        else // cnt가 k 미만 -> 현재 mid가 B[k] 미만 값임
        {
            low = mid + 1; // cnt 커져야 됨 -> 오른쪽 부분 탐색
        }
    }
    cout << low; // B[k]는 탐색을 종료한 뒤의 low(=high)이므로 low 출력
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    cin >> N;
    cin >> k;

    // 이분 탐색
    binarySearch();

    return 0;
}