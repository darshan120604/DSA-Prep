

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        // ------------------------------
        // STEP 1: Build the graph
        // ------------------------------
        // adj[u] will store a list of pairs (v, cost)
        // meaning there is an edge from u to v with given cost
        vector<vector<pair<int,int>>> adj(n);

        // Loop through each edge in the input
        for (auto &e : edges) {
            int u = e[0];   // starting node
            int v = e[1];   // ending node
            int w = e[2];   // cost of the edge

            // Add the original directed edge
            adj[u].push_back({v, w});

            // Add the reversed edge with double cost
            // This simulates using the "switch" at node v
            adj[v].push_back({u, 2 * w});
        }

        // ------------------------------
        // STEP 2: Initialize Dijkstra’s structures
        // ------------------------------

        // dist[i] will store the minimum cost to reach node i
        vector<long long> dist(n, LLONG_MAX);

        // Min-heap priority queue: stores (cost, node)
        // The smallest cost always comes out first
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        // Starting point: node 0, cost = 0
        dist[0] = 0;
        pq.push({0, 0});

        // ------------------------------
        // STEP 3: Run Dijkstra’s algorithm
        // ------------------------------
        while (!pq.empty()) {

            // Get the node with the smallest current cost
            auto [currentCost, u] = pq.top();
            pq.pop();

            // If we already found a better path to u, skip this one
            if (currentCost > dist[u]) {
                continue;
            }

            // Try to relax all edges going out from node u
            for (auto &[v, w] : adj[u]) {

                // If going through u gives a cheaper path to v
                if (dist[v] > currentCost + w) {

                    // Update the distance to v
                    dist[v] = currentCost + w;

                    // Push the updated distance into the heap
                    pq.push({dist[v], v});
                }
            }
        }

        // ------------------------------
        // STEP 4: Return the answer
        // ------------------------------

        // If destination node (n-1) is still unreachable, return -1
        if (dist[n - 1] == LLONG_MAX) {
            return -1;
        }

        // Otherwise, return the minimum cost found
        return dist[n - 1];
    }
};
