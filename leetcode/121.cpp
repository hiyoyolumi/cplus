class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int mini = 1e9;
        int maxi = 0;
        for (auto a : prices) {
            maxi = max(maxi, a - mini);
            mini = min(mini, a);
        }
        return maxi;
    }
};