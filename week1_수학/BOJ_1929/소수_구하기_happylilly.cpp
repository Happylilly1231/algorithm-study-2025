/*
알고리즘 : 수학 - 소수
시간 복잡도 : O(NloglogN)
참고 링크 :
    에라토스테네스의 체 - https://namu.wiki/w/%EC%86%8C%EC%88%98(%EC%88%98%EB%A1%A0)#s-7
아이디어 : 2, 3, 5 등 소수의 배수를 제외하고 나머지를 출력한다. -> 시간 초과(시간 복잡도가 이중 for문에서 둘 다 N까지이므로 O(N^2)이기 때문)
해결 방법 : 에라토스테네스의 체 - N까지의 합성수는 "제곱근 N까지만" 거르면 제거된다(합성수 x를 이루는 소수 중 하나는 제곱근 x보다 작기 때문)
*/

#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int M, N;

    cin >> M >> N;

    // 숫자 배열 생성
    int* numbers = new int[N + 1];
    for (int i = 0; i <= N; i++) {
        numbers[i] = i;
    }

    // 소수만 남기기
    numbers[1] = 0;                                        // 1 제외
    for (int i = 2; i <= sqrt(N); i++) {                   // 2부터 "제곱근 N까지"
        for (int j = i * i; j <= N; j += i) {              // i를 제외한 i의 배수이므로 j는 i * i부터 시작해서 i씩 더해줌
            if (numbers[j] != 0 && numbers[j] % i == 0) {  // 아직 걸러지지 않은 배수들 검사
                numbers[j] = 0;                            // 소수 아님
            }
        }
    }
    // // 이전 방식
    // numbers[1] = 0;                 // 1 제외
    // for (int i = 2; i <= N; i++) {  // 2부터 N까지 -> 문제
    //     for (int j = i + 1; j <= N; j++) {
    //         if (numbers[j] != 0 && numbers[j] % i == 0) {
    //             numbers[j] = 0;  // 소수 아님
    //         }
    //     }
    // }

    // 출력
    for (int i = M; i <= N; i++) {
        if (numbers[i] != 0) {
            cout << numbers[i] << endl;
        }
    }

    // 동적할당 메모리 해제
    delete[] numbers;

    return 0;
}