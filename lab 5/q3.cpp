#include <iostream>
#include <cstdlib>
using namespace std;

// Fast modular exponentiation
long long power(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

// Fermat Primality Test
bool isPrime(int n, int k = 5) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 4);
        if (power(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " is probably prime." << endl;
    else
        cout << n << " is composite." << endl;

    return 0;
}
