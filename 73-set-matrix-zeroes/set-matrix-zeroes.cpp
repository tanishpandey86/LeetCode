class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // Step 1: Check if first row has zero
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) firstRowZero = true;

        // Step 2: Check if first column has zero
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) firstColZero = true;

        // Step 3: Use first row/col as markers
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        // Step 4: Zero out interior cells based on markers
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // Step 5: Zero out first row if needed
        if (firstRowZero)
            for (int j = 0; j < n; j++) matrix[0][j] = 0;

        // Step 6: Zero out first column if needed
        if (firstColZero)
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};