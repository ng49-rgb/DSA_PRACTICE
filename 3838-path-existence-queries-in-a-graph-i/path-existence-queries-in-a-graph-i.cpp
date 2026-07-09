class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> compo(n,0);
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                // this means this i will belong to same component.
                compo[i] = compo[i-1];
            }
            else{
                compo[i] = compo[i-1] + 1 ; // reset compo
            }
        }

        int q=queries.size(); 
        vector<bool> ans(q,0); 
        for (int i = 0; i < q; i++) { 
            ans[i] = (compo[queries[i][0]] == compo[queries[i][1]]);
        }
        return ans;
    }
};