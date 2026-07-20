class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total_el = m * n;
        k = k % total_el;

        vector<vector<int>> shifted(m,vector<int>(n));
            for(int r = 0; r<m; r++){
                for( int c = 0; c<n; c++){
                    int idx_1D = (r * n + c + k) % total_el;
                    int new_2d_r = idx_1D / n;
                    int new_2d_c = idx_1D % n;
                    shifted[new_2d_r][new_2d_c] = grid[r][c];

                }

            } 
        return shifted;     
    }
};