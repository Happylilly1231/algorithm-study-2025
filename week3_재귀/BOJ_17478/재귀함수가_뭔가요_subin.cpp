#include <iostream>
#include <string>

using namespace std;

string underbar = "";

void jh(int n)
{
    string line = underbar;
    cout << underbar << "\"����Լ��� ������?\"\n";
    if (n == 0)
    {
        cout << underbar << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        cout << line << "��� �亯�Ͽ���.\n";
        return;
    }
    cout << underbar << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    cout << underbar << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    cout << underbar << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    underbar += "____";
    jh(--n);
    cout << line << "��� �亯�Ͽ���.\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    jh(n);

    return 0;
}