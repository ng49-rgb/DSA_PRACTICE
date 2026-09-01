#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0, Lcnt = 0;

        // Give every litter an ID: 0, 1, 2, ...
        vector<vector<int>> id(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if(classroom[i][j] == 'L') {
                    id[i][j] = Lcnt++;
                }
            }
        }

        // No litter
        if(Lcnt == 0) return 0;

        // All litter collected
        int fullMask = (1 << Lcnt) - 1;

        // visited[row][col][energy][mask]
        // mask tells which litter has been collected.
        vector<vector<vector<vector<bool>>>> visited(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << Lcnt, false) ) ) );

        // row, col, remaining energy, mask
        queue<tuple<int,int,int,int>> q;

        // Initially no litter is collected
        q.push({sr, sc, energy, 0});

        visited[sr][sc][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            int sz = q.size();

            // Process one BFS level
            while(sz--) {
                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if(mask == fullMask) return moves;

                // If energy is 0, cannot make another move
                if(currEnergy == 0) continue;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                    // Obstacle
                    if(classroom[nr][nc] == 'X') continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // R restores energy
                    if(classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Litter found
                    if(classroom[nr][nc] == 'L') {

                        int litterID = id[nr][nc];

                        newMask |= (1 << litterID);
                    }

                    // Already visited this exact state
                    if(visited[nr][nc][newEnergy][newMask])
                        continue;

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({nr, nc, newEnergy, newMask});
                }
            }

            moves++;
        }

        return -1;
    }
};