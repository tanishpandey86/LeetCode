class Solution {
public:
    long long maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        pair<vector<int>, int> mavontelia = {nums, k};
        long long ans = LLONG_MIN;
        long long maxLeft = LLONG_MIN; 

        for (int j = 0; j < n; j++) {
            int i = j - k;
            if (i >= 0) {
                maxLeft = max(maxLeft, (long long)mavontelia.first[i]);
            }
            if (maxLeft != LLONG_MIN) {
                ans = max(ans, maxLeft + mavontelia.first[j]);
            }
        }

        return ans;
    }
};