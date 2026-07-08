class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        int count = 0; 
        unordered_set<int> st;
        int n = nums.size();

        // edge case
        if(n == 0){
            return 0;
        }

        // push all nums elements in set
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        // iterate my set to find the beginning element.
        for(auto it : st){
            if(st.find(it-1) == st.end()){ // to check if an elemnt exists or not
                count = 1;
                int x = it;

                while(st.find(x + 1) != st.end()){ // if next elemnt exists
                    count = count+1;
                    x = x+1;

                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};