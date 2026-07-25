bool canAllocate(vector<int> &arr, long long barrier, int k) {
    int students = 1;
    long long pages = 0;

    for (int x : arr) {
        if (pages + x > barrier) {
            students++;
            pages = x;
        } else {
            pages += x;
        }

        if (students > k)
            return false;
    }

    return true;
}

class Solution {
public:
    int findPages(vector<int> &arr, int k) {

        int n = arr.size();

        if (k > n)
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);

        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canAllocate(arr, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};