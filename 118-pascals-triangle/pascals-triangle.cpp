class Solution {
public:

    vector<int> genRow(int row) {
        long long ans = 1;
        vector<int> ans_row;

        ans_row.push_back(1);

        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ans_row.push_back(ans);
        }

        return ans_row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            ans.push_back(genRow(i));
        }

        return ans;
    }
};