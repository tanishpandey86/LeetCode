class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        unordered_set<int> added; // To avoid duplicates in result
        
        for (int x : nums2) {
            if (s.count(x) && !added.count(x)) {
                ans.push_back(x);
                added.insert(x);
            }
        }
        return ans;
    }
};
