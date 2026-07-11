class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,int &v, int &e) {

        visited[node] = true;
        v++;                        
        e += adj[node].size();      // Sum of degrees

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        int res = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {

            if (visited[i]) {
                continue;
            }

            int vertices = 0;
            int degreeSum = 0;

            dfs(i, adj, visited, vertices, degreeSum);

            // degreeSum = 2 * number of edges
            if (vertices * (vertices - 1) == degreeSum) {
                res++;
            }
        }

        return res;
    }
};