/*
 // 整数的最大质因数
*/

#include <iostream>
using namespace std;

void trial_divisio_fac(long long n) {
    long long a  = 2;
    while(a * a <= n) {
        while(n % a == 0) {
            cout << a << " ";
            n /= a;
        }

        a = a + 1;
    }

    if(n > 1) cout << n;
    cout << endl;
}

int main () {
    long long n = 17;
    while(cin >> n) {
        trial_divisio_fac(n);
    }
}