#include <iostream>
using namespace std;

int main () {
    long long sum = 0;
    long long a1 = 1, a2 = 2;
    while(a2 < 4000000) {
        if(a2 % 2 == 0) { sum += a2; }
        long long tmp = a1 + a2;
        a1 = a2; a2 = tmp;
    }

    cout << sum << endl;
}