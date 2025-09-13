class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;
        int count = 0, sum = 0;
        for (int num : nums) {
            sum += num;
            if (prefixSums.find(sum - k) != prefixSums.end()) {
                count += prefixSums[sum - k];
            }
            prefixSums[sum]++;
        }
        return count;
    }
};
