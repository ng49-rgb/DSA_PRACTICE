// via hashmap
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sor_arr = arr;
        
        sort(sor_arr.begin(), sor_arr.end());

        int r = 1;
        unordered_map<int,int> rankMap;

        for(auto it : sor_arr){
            if(rankMap.find(it) == rankMap.end()){
            rankMap[it] = r++;
}
        }

        vector<int> ans;
        for(auto it : arr){
            ans.push_back(rankMap[it]);

        }

        return ans;
    }
};