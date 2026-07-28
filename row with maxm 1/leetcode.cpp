class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {0, 0};
        
        int maxRowIndex = 0;
        int maxOnesCount = -1;
        // Iterate through each row to count ones
        for (int i = 0; i < mat.size(); i++) {
            int currentOnesCount = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    currentOnesCount++;
                }
            }
            // Track the row with the maximum number of ones
            if (currentOnesCount > maxOnesCount) {
                maxOnesCount = currentOnesCount;
                maxRowIndex = i;
            }
        }
        
        return {maxRowIndex, maxOnesCount};
    }
};
