int maxIdx(vector<vector<int>>& mat, int m, int n, int col) {
    int maxValue = -1;
    int idx = -1;

    for (int i = 0; i < m; i++) {   // iterate over rows
        if (mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            idx = i;
        }
    }

    return idx;
}

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int rowIdx = maxIdx(mat, m, n, mid);

            int left  = (mid > 0) ? mat[rowIdx][mid - 1] : -1;
            int right = (mid < n - 1) ? mat[rowIdx][mid + 1] : -1;

            if (mat[rowIdx][mid] > left && mat[rowIdx][mid] > right)
                return {rowIdx, mid};

            if (mat[rowIdx][mid] < left)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};