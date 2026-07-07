class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) {
            arr[0] = -1;
            return arr;
        }

        for (int i = 0; i < n - 1; i++) {
            int leader = arr[i + 1];

            for (int j = i + 1; j < n; j++) {
                leader = max(leader, arr[j]);
            }

            arr[i] = leader;
        }

        arr[n - 1] = -1;

        return arr;
    }
};