class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i = n - 1, j = m - 1, k = n + m - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};