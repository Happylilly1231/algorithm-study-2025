/*
알고리즘 : 수학 - 최대 공약수
시간 복잡도 : O(NM)
참고 링크 : x
아이디어 : 수의 크기가 매우 크므로 곱해서 구하지 않고 두 수씩 최대 공약수를 계산하며 그것을 곱해서 구한다. 이중 for문으로 돌리면서 배열 A 원소와 배열 B 원소의 최대공약수를 유클리드 호제법으로 구하고, 그 최대 공약수를 모두 곱해 결과값을 구한다.(만약 9자리를 넘어가면 나머지를 연산을 해줘서 오버플로우를 방지한다.)
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int get_gcd(int a, int b);  // 유클리드 호제법 최대 공약수 구하는 함수

int main() {
    int N, M, gcd;
    long long int gcd_result = 1;  // 최대 공약수 결과
    bool isBigNumber;              // 실제 결과값이 9자리보다 큰지 여부

    // N개 입력 받아서 배열 A에 저장
    cin >> N;
    int* arr_A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr_A[i];
    }

    // M개 입력 받아서 배열 B에 저장
    cin >> M;
    int* arr_B = new int[M];
    for (int i = 0; i < M; i++) {
        cin >> arr_B[i];
    }

    // 최대 공약수 구하기
    // 배열 A를 기준으로 이중 for문 돌리면서
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 배열 A의 원소 하나를 기준으로 배열 B의 원소를 차례로 가져와서 최대 공약수 계산
            gcd = get_gcd(arr_A[i], arr_B[j]);

            // 구한 최대 공약수로 나눈 몫을 각 원소에 남겨두기(최대 공약수에 포함되지 못한 각각의 약수를 남겨두는 것(후에 공약수가 될 수도 있음))
            arr_A[i] /= gcd;
            arr_B[j] /= gcd;

            // 전체 최대 공약수 결과값에 현재 계산한 원소들의 최대 공약수 곱해주기
            gcd_result *= gcd;

            // 만약 9자리보다 크면 10억(10자리) 나머지 연산으로 9자리 이하로 만들어주기(중간에 나머지 연산을 해도 어차피 결과를 일의 자리 수부터 보여주기 때문에 곱셈에서는 상관 없음)
            if (gcd_result >= 1000000000) {
                isBigNumber = true;  // 실제 결과값이 9자리보다 큰지 여부를 true로 설정
                gcd_result %= 1000000000;
            }
        }
    }

    // 출력
    if (isBigNumber)                 // 실제 결과값이 9자리보다 크면
        printf("%09d", gcd_result);  // 9자리에서 빈 앞자리 0으로 채우기
    else                             // 9자리보다 작으면
        cout << gcd_result;          // 그냥 출력

    return 0;
}

// 유클리드 호제법으로 최대 공약수 구하기
int get_gcd(int a, int b) {
    if (b == 0) return a;
    return get_gcd(b, a % b);  // 만약 a < b 여도, a % b를 하면 자리가 바뀌게 되므로 크기 비교할 필요 X
}