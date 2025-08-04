/*
알고리즘: 자료구조 - 트리
시간 복잡도:
    - 삭제: O(n)
    - 리프노드 탐색 : O(n)
참고 링크:
    - 도움받았던 반례: https://www.acmicpc.net/board/view/104534
아이디어: 이차원 벡터로 부모 벡터 아래 자식 벡터 구현하고, 부모를 중심으로 자식 벡터를 순회하며 재귀적으로 삭제하고 탐색하자. 예제를 보고 조건을 판단하지 말고 문제에 명시된 조건만이 전제임을 주의하자.
*/

#include <iostream>
#include <vector>

using namespace std;

void removeNode(vector<vector<int>> &v, int id)
{
    if (v[id].empty())
        return;

    for (int child : v[id])
    {
        removeNode(v, child);
    }
    v[id].clear();
}

int getLeafNodeCount(vector<vector<int>> &v, int id, int remove_id)
{
    if (v[id].empty()) // 애초에 자식이 없으면
        return 1;      // 리프노드

    int cnt = 0, flag = 0;
    for (int child : v[id])
    {
        if (child != remove_id)
        {
            cnt += getLeafNodeCount(v, child, remove_id);
            flag = 1;
        }
    }

    if (flag == 0)  // 자식이 삭제돼서 순회할 대상이 아예 없으면
        return 1;   // 자기 자신이 리프 노드
    else            // 자식을 순회했으면 자식 중에 리프 노드가 있음
        return cnt; // 리프노드가 될 수 없음
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, parent_id, remove_id, root_id;

    vector<vector<int>> v(50);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> parent_id;
        if (parent_id == -1)
            root_id = i;
        else
            v[parent_id].push_back(i);
    }

    cin >> remove_id;

    if (root_id == remove_id)
        cout << 0 << '\n';
    else
    {
        removeNode(v, remove_id);
        cout << getLeafNodeCount(v, root_id, remove_id) << '\n';
    }

    return 0;
}
