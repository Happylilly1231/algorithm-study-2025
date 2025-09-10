/*
알고리즘: 이분탐색
시간 복잡도: O(Klog(maxLength))
참고 링크:
    - 이분탐색
        - https://m42-orion.tistory.com/69
아이디어:
    - 빠르게 값에 도달하기 위해 이분탐색을 사용한다.
    - K개 각각의 길이를 고려하지 않았을 때 이론적으로 가능한 최대 길이(= 가지고 있는 K개의 랜선의 합 / 만들어야 하는 개수 N)를 도출하여 처음 high로 설정한다.
    - 현재 랜선 목표길이 mid만큼 각각의 랜선에서 몇 개씩 만들 수 있는지 검사하여 만든 랜선의 전체 개수 cnt 계산
        - 만든 랜선의 전체 개수 cnt가 N개 이상 -> 길이를 더 크게 잡기(mid의 오른쪽 탐색) & 최대 길이 갱신
        - N개를 넘지 않으면 -> 길이를 작게 잡기(mid의 왼쪽 탐색)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int N;             // 필요한 랜선의 개수
long long sum = 0; // K개 랜선 길이의 합

// 이분 탐색
void binarySearch()
{
    long long low = 1;
    long long high = sum / N; // K개 각각의 길이를 고려하지 않았을 때 이론적으로 가능한 최대 길이
    long long max = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2; // 현재 랜선 목표 길이

        // 현재 랜선 목표 길이만큼 각각의 랜선에서 몇 개씩 만들 수 있는지 검사, 전체 개수 계산
        int cnt = 0; // 만든 랜선의 전체 개수
        for (auto x : v)
        {
            cnt += (x / mid);
        }

        if (cnt >= N) // 만든 랜선의 전체 개수가 N개 이상일 때
        {
            low = mid + 1; // 길이를 더 크게 잡기

            // 최대 길이 갱신
            if (mid > max)
            {
                max = mid;
            }
        }
        else // 만든 랜선의 전체 개수가 N개를 넘지 않을 때
        {
            high = mid - 1; // 길이를 더 작게 잡기
        }
    }

    // 결과 출력
    cout << max << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K, x;

    // 입력
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    // 이분 탐색
    binarySearch();

    return 0;
}