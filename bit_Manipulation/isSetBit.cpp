#include<iostream>
using namespace std;

bool isSetBit(int num, int i) {
    return (num & (1 << i));
}

int main() {
    int i = 2;
    
    int num = 13;

    bool ans = isSetBit(num, i);

    cout << ans << endl;

    return 0;
}
