class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        long long ans = 0;
        int prefXor = 0;

        for (int num : nums) {
            prefXor ^= num;
            ans += freq[prefXor];
            freq[prefXor]++;
        }

        return ans;
    }
};