class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;

        // Sort the values
        sort(vec.begin(), vec.end());

        // Group number for each value
        int groupNum = 0;
        unordered_map<int, int> numToGroup;

        numToGroup[vec[0]] = groupNum;

        // Store values belonging to each group
        unordered_map<int, list<int>> groupToList;
        groupToList[groupNum].push_back(vec[0]);

        // Create groups
        for (int i = 1; i < n; i++) {

            // If consecutive sorted values cannot be swapped,
            // start a new group
            if (abs(vec[i] - vec[i - 1]) > limit) {
                groupNum++;
            }

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        // Build the answer
        vector<int> result(n);

        for (int i = 0; i < n; i++) {

            int num = nums[i];
            int group = numToGroup[num];

            // Take the smallest unused value
            // from this group
            result[i] = groupToList[group].front();

            groupToList[group].pop_front();
        }

        return result;
    }
};