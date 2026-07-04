// approach: just simple traversal will work as it is given that 1 and n are always connected , hence
// just traverse all path and select min dist for each path.
class Solution {
public:

    // dfs
    void dfs(int u, unordered_map<int, vector<pair<int,int>>> &adj,
             vector<bool> &visited, int &result){

        visited[u] = true;

        // neighbour
        for(auto &P : adj[u]){
            int v = P.first;
            int dist = P.second;

            result = min(result, dist);

            if(!visited[v]){
                dfs(v, adj, visited, result);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        // adj list
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &vec : roads){
            int u = vec[0];
            int v = vec[1];
            int dist = vec[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<bool> visited(n + 1, false);

        int result = INT_MAX;

        dfs(1, adj, visited, result);

        return result;
    }
};