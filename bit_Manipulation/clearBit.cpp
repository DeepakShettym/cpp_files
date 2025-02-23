#include <iostream>
using namespace std;

int clearBit(int num, int i) {
    int ans = num & ~(1 << i);
    return ans;
}

int main() {
    int ans = clearBit(2, 1);  
    cout << ans << endl;       

    return 0;
}
