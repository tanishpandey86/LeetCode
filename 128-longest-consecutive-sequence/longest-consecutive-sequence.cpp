class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                int cnt = 1;
                while (st.count(x + 1)) {
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};