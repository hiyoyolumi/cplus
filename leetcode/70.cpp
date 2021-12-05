#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 0, c = 1;
        for (int i = 0; i < n; i++) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};

void test01() {
    Solution a;
    cout << a.climbStairs(45) << endl;
}

int main() {
    test01();

    return 0;
}