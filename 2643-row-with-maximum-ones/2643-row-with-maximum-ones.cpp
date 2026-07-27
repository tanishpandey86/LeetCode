class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxRow = 0;
        int maxCount = -1;

        for (int i = 0; i < mat.size(); i++) {
            int ones = count(mat[i].begin(), mat[i].end(), 1);
            if (ones > maxCount) {
                maxCount = ones;
                maxRow = i;
            }
        }

        return {maxRow, maxCount};
    }
};