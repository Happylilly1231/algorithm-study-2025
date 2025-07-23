/*
알고리즘 : 수학 - 최소 공배수
시간 복잡도 : O(N) -> 추후 유클리드 호제법로 최대 공약수 구해서 최소 공배수 구하는 방법으로 바꿨는데 해당 시간 복잡도는 O(log n)
참고 링크 :
    이 코드와 관련된 건 아니지만 추후 개선을 위해 찾아본 참고 자료
    최대공약수, 유클리드 호제법 - https://velog.io/@skdbsqls/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98%EC%99%80-%EC%B5%9C%EC%86%8C%EA%B3%B5%EB%B0%B0%EC%88%98-%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C-%ED%98%B8%EC%A0%9C%EB%B2%95
    유클리드 호제법 - https://wikidocs.net/205459
    유클리드 호제법 - https://wyatti.tistory.com/entry/Cc-%EC%B5%9C%EB%8C%80-%EA%B3%B5%EC%95%BD%EC%88%98
아이디어 : 일단 두 수 중에 큰 수부터 시작해서 둘의 약수(공약수x)를 차례대로 곱해보면서 최소공배수를 반복문으로 계산하자
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long long int get_lcm(int a, int b);  // 최소 공배수 구하는 함수

int main() {
    int n;              // 테스트 케이스 개수
    int a, b;           // 두 수
    long long int lcm;  // 최소 공배수(최대 12자리 수기 때문에 long long int로 설정)

    cin >> n;  // 테스트 케이스 입력

    // 테스트 케이스 개수만큼 반복
    for (int i = 0; i < n; i++) {
        cin >> a >> b;  // 두 수 입력

        // 큰 수를 왼쪽 인자, 즉 large_number로 넣어줌
        if (a >= b)
            lcm = get_lcm(a, b);  // 최소 공배수 구하기
        else
            lcm = get_lcm(b, a);  // 최소 공배수 구하기

        cout << lcm << endl;  // 출력
    }

    return 0;
}

// 최소 공배수 구하는 함수
long long int get_lcm(int large_number, int small_number) {
    long long int lcm;  // 최소 공배수

    // 둘의 약수를 차례로 큰 수에 곱해가며 최소 공배수인지 확인
    for (int i = 1; i <= large_number && i <= small_number; i++) {  // 둘의 약수를 검사할 것이므로 i는 두 수보다 같거나 작아야 함
        if (large_number % i == 0 || small_number % i == 0) {       // i는 a의 약수거나 b의 약수여야 함(아닌 경우 바로 넘어가기)
            // 큰 수에 i를 곱한 것이 최소 공배수인지 확인
            lcm = (long long)large_number * i;
            if (lcm % small_number == 0) {
                break;  // 맞으면 탈출
            }
        }
    }

    return lcm;  // 최소 공배수 반환
}