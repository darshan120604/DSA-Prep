class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {
        const long long INF = 1e18;

        // Step 1: Create distance matrix for 26 characters
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // Distance from a character to itself is 0
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // Step 2: Fill direct transformation costs
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Step 3: Floyd-Warshall to compute all-pairs shortest paths
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 4: Calculate total minimum cost
        long long totalCost = 0;
        int n = source.size();

        for (int i = 0; i < n; i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (s == t) continue; // No cost needed

            if (dist[s][t] == INF) {
                return -1; // Conversion impossible
            }

            totalCost += dist[s][t];
        }

        return totalCost;
    }
};
