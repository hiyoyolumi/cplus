#include <iostream>
#include <vector>
#include <algorithm> // 算法

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = 0, b = 0;
        int sorted[m + n];
        int cur = 0;
        int num = 0;
        while (a < m || b < n) {
            if (a == m) {
                cur = nums2[b++];
            } else if (b == n) {
                cur = nums1[a++];
            } else if (nums1[a] < nums2[b]) {
                cur = nums1[a++];
            } else {
                cur = nums2[b++];
            }
            sorted[num++] = cur;
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = sorted[i];
        }
    }
};

void test01() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    sort(nums2.begin(), nums2.end());
    Solution test;
    test.merge(nums1, 3, nums2, nums2.size());
    for (auto i = nums1.begin(); i != nums1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    test01();

    return 0;
}