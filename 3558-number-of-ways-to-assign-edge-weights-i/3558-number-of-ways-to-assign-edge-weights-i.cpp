#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        // Step 1: Build the adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: BFS to find the maximum depth
        int max_depth = 0;
        vector<int> depth(n + 1, -1);
        queue<int> q;

        q.push(1);
        depth[1] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            max_depth = max(max_depth, depth[u]);

            for (int v : adj[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    q.push(v);
                }
            }
        }

        // Step 3: Compute 2^(max_depth - 1) % (10^9 + 7)
        return power(2, max_depth - 1, 1000000007);
    }

private:
    long long power(long long base, long long exp, int mod) {
        if (exp < 0) return 0; // Should not happen given constraints
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};
