#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int mid = 0;
        int res = 0;
        while (l < r) {
            mid = (l + r)/2;
            if (mid * mid <= x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};

void test01() {
    int x = 4;
    Solution test;
    cout << test.mySqrt(x) << endl;
}

int main() {
    test01();

    return 0;
}