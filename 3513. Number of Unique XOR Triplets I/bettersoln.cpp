class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 || n == 2){
            return n;
        }

        int ans = 1; // 2^0
        while(ans <= n){
            ans = ans << 1; // ans *= 2 
        }
        return ans;
    }
};

// brute would simply be in O n^3 ; as 3 loops for 1 triplet.
// unordered_set<int> unique_xors;
        
//         // O(N^3) Brute Force
//         for (int i = 0; i < n; ++i) {
//             for (int j = i; j < n; ++j) {
//                 for (int k = j; k < n; ++k) {
//                     int xor_val = nums[i] ^ nums[j] ^ nums[k];
//                     unique_xors.insert(xor_val);
//                 }
//             }
//         }
//         return unique_xors.size();