## 01. Path Exists Between Two Vertices

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/path-exists/1)

### Problem Description

**Task:** Given an undirected graph with V vertices numbered from 0 to V - 1, represented by an adjacency list adj[][], where adj[i] contains all vertices adjacent to vertex i. Also given two vertices u and v, check whether a path exists between them.Return true if a path exists, otherwise return false.Examples: Input: adj[][] = [[2, 3], [2], [0, 1], [0], [5], [4]], u = 1, v = 5Output: falseExplanation: There is no path from vertex 1 to vertex 5.Input: adj[][] = [[2, 3], [2], [0, 1], [0], [5], [4]], u = 2, v = 3

#### Examples

##### Example 1

- **Output:**
```text
true
```
- **Explanation:** We can reach vertex 3 from vertex 2 via vertex 0.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(V + E)
- **Expected Auxiliary Space Complexity:** O(V + E)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-28 19:08:22
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        if (u == v) return true;

        int V = adj.size();
        vector<bool> visited(V, false);
        queue<int> q;

        visited[u] = true;
        q.push(u);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (neighbor == v) {
                    return true;
                }
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};
```

*Generated on: 28/11/2026, 23:59:09*