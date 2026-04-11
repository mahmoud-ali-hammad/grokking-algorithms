#include <iostream>
using namespace std;

int fact(int x) {
    if (x == 1) {
        return 1;   // base case
    } else {
        return x * fact(x - 1);  // recursive call
    }
}

int main() {
    cout << fact(3);
    return 0;
}