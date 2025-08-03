/*
알고리즘 : 자료구조 - 트리
시간 복잡도 :
    - 탐색: O(n)
    - 삽입/삭제: O(n)
참고 링크 : x
아이디어 : Node 구조체를 만들고, 삽입할 때는 먼저 해당 값을 가진 노드를 찾은 다음에 삽입한다. 재귀로 왼쪽 자식 오른쪽 자식을 순회한다.
*/

#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *findNode(Node *root, char value);
void insertNode(Node *root, char p, char lc, char rc);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    char p, lc, rc;

    cin >> N;

    Node *root = new Node('A'); // 루트 설정

    for (int i = 0; i < N; i++)
    {
        cin >> p >> lc >> rc;
        insertNode(root, p, lc, rc);
    }

    preorder(root); // 전위 순회
    cout << '\n';

    inorder(root); // 중위 순회
    cout << '\n';

    postorder(root); // 후위 순회

    return 0;
}

// 같은 값을 가진 노드 찾기
Node *findNode(Node *root, char value)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == value)
    {
        return root;
    }

    Node *node = findNode(root->left, value);

    if (node == nullptr)
        node = findNode(root->right, value);

    return node;
}

// 노드 삽입
void insertNode(Node *root, char p, char lc, char rc)
{
    Node *node = findNode(root, p);

    node->left = new Node(lc);
    node->right = new Node(rc);
}

// 전위 순회 : 루트 -> 왼쪽 자식 -> 오른쪽 자식
void preorder(Node *root)
{
    if (root->data == '.')
        return;

    cout << root->data;
    preorder(root->left);  // 왼쪽 자식
    preorder(root->right); // 오른쪽 자식
}

// 중위 순회 : 왼쪽 자식 -> 루트 -> 오른쪽 자식
void inorder(Node *root)
{
    if (root->data == '.')
        return;

    inorder(root->left); // 왼쪽 자식
    cout << root->data;
    inorder(root->right); // 오른쪽 자식
}

// 후위 순회 : 왼쪽 자식 -> 오른쪽 자식 -> 루트
void postorder(Node *root)
{
    if (root->data == '.')
        return;

    postorder(root->left);  // 왼쪽 자식
    postorder(root->right); // 오른쪽 자식
    cout << root->data;
}