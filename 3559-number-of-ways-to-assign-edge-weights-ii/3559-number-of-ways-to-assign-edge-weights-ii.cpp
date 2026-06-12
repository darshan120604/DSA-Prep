#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;

    void dfs(int u, int p, int d) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOG; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;
        adj.assign(n + 1, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);
        
        // Start DFS from root node 1
        dfs(1, 1, 0);

        // Precompute powers of 2 mod 10^9 + 7
        long long MOD = 1e9 + 7;
        vector<int> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
            } else {
                int lca = get_lca(u, v);
                int k = depth[u] + depth[v] - 2 * depth[lca];
                ans.push_back(pow2[k - 1]);
            }
        }
        return ans;
    }
};
