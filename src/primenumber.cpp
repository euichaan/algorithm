#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// O(N)으로 소수 판별
bool isPrime1(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// O(√N)으로 소수 판별
// 2 ~ 제곱근까지의 수 중, 해당 수와 나누어떨어지는 수가 있는지 확인을 한 뒤,
// 나누어떨어지는 수가 있다면 (약수가 있다면) 소수가 아니고, 없다면 소수가 된다.
bool isPrime2(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// O(Nlog(logN))으로 소수 판별: 에라토스테네스의 체
// 예를 들어 2는 소수이다. 하지만 2를 제외한 2의 배수인 4, 6, 8, 10, ... 들은 약수로 2를 가지고 있어 소수가 되지 못한다.
// 3은 소수이다. 하지만 3을 제외한 3의 배수인 6, 9, 12, 15, 18, 21 ..... 들은 모두 약수로 3을 가지고 있으므로, 소수가 되지 못한다.
// n까지의 수 중, 소수를 출력
void isPrime3(int n) {
    bool *isPrime = new bool[n+1];

    for (int i = 0; i <= n; i++) isPrime[i] = 1;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) { // 소수라면 출력하고 해당수를 제외한 배수들을 모두 제외
            cout << i << " ";
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    isPrime3(50);
}