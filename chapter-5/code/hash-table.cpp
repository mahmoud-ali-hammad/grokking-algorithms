#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, double> book;

    book["apple"] = 0.67;
    book["milk"] = 1.49;
    book["avocado"] = 1.49;

    cout << book["avocado"] << endl; // 1.49

    return 0;
}