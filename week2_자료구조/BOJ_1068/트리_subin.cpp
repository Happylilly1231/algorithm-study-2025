/*
    알고리즘 : 자료구조 - 트리
    시간복잡도 : O(n)
    참고자료 : remove-erase idiom(https://velog.io/@doorbals_512/C-erase%EC%99%80-remove-%ED%95%A8%EC%88%98%EC%9D%98-%EC%B0%A8%EC%9D%B4)
    아이디어 : C++ STL의 map을 이용해 부모 노드를 key로,
              자식 노드를 vector를 이용해 저장
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<int>> tree;
int leaf_node_cnt = 0;

void removeNode(int remove_node)
{
    for (int child : tree[remove_node])
    {
        removeNode(child);
    }
    tree.erase(remove_node);
}

void getLeafNodeCnt(int node)
{
    if (tree.find(node) == tree.end() || tree[node].empty())
    {
        leaf_node_cnt++;
        return;
    }

    for (int child : tree[node])
    {
        getLeafNodeCnt(child);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, root_node = -1, remove_node;
    vector<int> parent(51);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
        if (parent[i] == -1)
        {
            root_node = i;
        }
        else
        {
            tree[parent[i]].push_back(i);
        }
    }

    cin >> remove_node;

    if (remove_node == root_node)
    {
        cout << 0;
        return 0;
    }

    for (auto &entry : tree)
    {
        auto &children = entry.second;
        children.erase(remove(children.begin(), children.end(), remove_node), children.end());
    }

    removeNode(remove_node);
    getLeafNodeCnt(root_node);

    cout << leaf_node_cnt;

    return 0;
}