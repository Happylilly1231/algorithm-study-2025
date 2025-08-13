/*
알고리즘: 재귀
시간 복잡도: O(N^2)
참고 링크:
    - 동적 프로그래밍: https://ansohxxn.github.io/algorithm/dp/
아이디어: 한 번 재귀로 구한 피보나치 수는 벡터에 저장해서 바로 값을 얻어올 수 있도록 한다. 수의 범위가 매우 크므로 10^8을 기준으로 v[n]의 int 벡터에 쪼개서 저장한다.(인덱스가 커질 수록 높은 자리 수를 저장한다.) 쪼개진 것들의 합이 10^8을 넘으면 더하기 연산에서 올림 수를 제외한 나머지는 해당 자리에 저장하고, 올림 수는 다음 자리에 합해 저장하는 것처럼 구현했다.
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

constexpr int bigNum = 100000000; // 수들을 int로 저장할 것이므로 int 범위를 넘지 않는 선에서 적당한 1억(10^8)으로 설정해주었다. 따라서 벡터에 담긴 모든 수는 8자리 이하로 저장된다.

vector<vector<int>> v(10001); // n의 최대 범위: 10000

// v[n][idx]에 이미 값이 저장되어 있으면 그 값에 num을 더하고, 접근이 불가하면(=저장되어 있지 않으면) v[n]에 맨 뒤에 num을 삽입한다.
void addOrInsert(int n, int idx, int num)
{
    if (v[n].size() > idx)
        v[n][idx] += num;
    else
        v[n].push_back(num);
}

// 피보나치 함수
vector<int> fibonacci(int n)
{
    if (!v[n].empty()) // 저장되어 있으면
        return v[n];   // 저장값 반환

    // 저장 안되어 있으므로 계산해서 저장
    vector<int> v1 = fibonacci(n - 1);
    vector<int> v2 = fibonacci(n - 2);

    int i;
    for (i = 0; i < v1.size() && i < v2.size(); i++)
    {
        int sum = v1[i] + v2[i]; // 쪼개진 것들의 합
        if (sum > bigNum)        // 10^8을 넘으면
        {
            addOrInsert(n, i, sum % bigNum);     // 나머지 저장(이미 값이 있으면 더해주기)
            addOrInsert(n, i + 1, sum / bigNum); // 올림수 다음 인덱스에 저장(이미 값이 있으면 더해주기)
        }
        else
        {
            addOrInsert(n, i, sum); // 합 저장(이미 값이 있으면 더해주기)
        }
    }
    for (int j = i; j < v1.size(); j++) // v1 벡터가 남아있으면
    {
        addOrInsert(n, j, v1[j]); // v1 벡터의 남은 수들 저장해주기(이미 값이 있으면 더해주기)
    }
    for (int j = i; j < v2.size(); j++) // v2 벡터가 남아있으면
    {
        addOrInsert(n, j, v2[j]); // v2 벡터의 남은 수들 저장해주기(이미 값이 있으면 더해주기)
    }

    return v[n]; // 저장값 반환
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    // 0과 1은 직접 초기화
    v[0].push_back(0);
    v[1].push_back(1);

    vector<int> res = fibonacci(n);

    cout << res.back();                                      // 맨 뒤(가장 높은 자리들)는 0이 앞에 붙으면 안되므로 따로 출력
    for (auto it = res.rbegin() + 1; it != res.rend(); it++) // 역순으로 출력(인덱스 높을 수록 높은 자리가 저장되어 있기 때문)
    {
        cout << setw(8) << setfill('0') << *it; // 앞에 남은 자리에 0 붙여서 출력(8자리 고정)
    }

    return 0;
}