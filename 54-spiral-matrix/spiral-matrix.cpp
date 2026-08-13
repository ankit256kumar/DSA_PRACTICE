
        class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int srow = 0;
        int scol = 0;
        int erow = m - 1;
        int ecol = n - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            // TOP
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }

            // RIGHT
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            // BOTTOM
            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--) {
                    ans.push_back(matrix[erow][j]);
                }
            }

            // LEFT
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--) {
                    ans.push_back(matrix[i][scol]);
                }
            }

            // Shrink boundary
            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};
        
