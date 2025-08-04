/*
    알고리즘 : 자료구조 - 트리
    시간복잡도 : O(n)
    아이디어 : C++ STL의 map을 이용해 각 노드를 key로,
              make_pair로 왼쪽 자식 노드, 오른쪽 자식 노드를 저장
*/

#include <iostream>
#include <map>

using namespace std;

map<char, pair<char, char>> tree;

/// @brief 전위순회 - 루트/왼쪽 자식/오른쪽 자식
/// @param node 현재노드
void preorder(char node)
{
    cout << node;
    if (tree[node].first != '.')
    {
        preorder(tree[node].first);
    }
    if (tree[node].second != '.')
    {
        preorder(tree[node].second);
    }
}

/// @brief 중위순회 - 왼쪽 자식/루트/오른쪽 자식
/// @param node
void inorder(char node)
{
    if (tree[node].first != '.')
    {
        inorder(tree[node].first);
    }
    cout << node;
    if (tree[node].second != '.')
    {
        inorder(tree[node].second);
    }
}

/// @brief 후위순회 - 왼쪽 자식/오른쪽 자식/루트
/// @param node
void postorder(char node)
{
    if (tree[node].first != '.')
    {
        postorder(tree[node].first);
    }
    if (tree[node].second != '.')
    {
        postorder(tree[node].second);
    }
    cout << node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, flag = 0;
    char node, left, right;
    char root;

    cin >> n;

    while (n--)
    {
        cin >> node >> left >> right;
        if (flag == 0)
        {
            root = node;
            flag = 1;
        }
        tree[node] = make_pair(left, right);
    }

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);

    return 0;
}
