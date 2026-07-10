class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums,
                                     int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> pos(n);

        vector<int> comp(n);

        int component = 0;

        pos[arr[0].second] = 0;
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            pos[arr[i].second] = i;

            if (arr[i].first - arr[i - 1].first > maxDiff)
                component++;

            comp[i] = component;
        }

        // nxt[i] = farthest sorted position reachable in one edge
        vector<int> nxt(n);
        int right = 0;

        for (int left = 0; left < n; left++) {
            while (right + 1 < n &&
                   arr[right + 1].first - arr[left].first <= maxDiff)
                right++;

            nxt[left] = right;

            if (right == left)
                right++;
        }

        const int LOG = 20;
        vector<vector<int>> jump(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            jump[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                jump[k][i] = jump[k - 1][jump[k - 1][i]];
            }
        }

        vector<int> answer;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            if (comp[u] != comp[v]) {
                answer.push_back(-1);
                continue;
            }

            if (u > v)
                swap(u, v);

            int curr = u;
            int edges = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (jump[k][curr] < v) {
                    curr = jump[k][curr];
                    edges += (1 << k);
                }
            }

            answer.push_back(edges + 1);
        }

        return answer;
    }
};