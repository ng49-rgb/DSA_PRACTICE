class Solution {
public:
    bool dijkstra(unordered_map<int, vector<pair<int, int>>> &adj,
                  int n, long long k, int mid) {

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {

                // Ignore edges whose weight is smaller than mid
                if (w < mid) continue;

                if (cost + w < dist[v]) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        // Source or destination offline
        if (!online[0] || !online[n - 1])
            return -1;

        unordered_map<int, vector<pair<int, int>>> adj;

        int l = INT_MAX;
        int r = INT_MIN;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if (!online[u] || !online[v])
                continue;

            adj[u].push_back({v, cost});

            l = min(l, cost);
            r = max(r, cost);
        }

        // No usable edges
        if (l == INT_MAX)
            return -1;

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (dijkstra(adj, n, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};