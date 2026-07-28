class Solution {
public:
    int upperBound(vector<int> &arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int cntMax = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int cntOnes = m - upperBound(mat[i], m, 0);

            if (cntOnes > cntMax) {
                cntMax = cntOnes;
                index = i;
            }
        }

        return index;
    }
};