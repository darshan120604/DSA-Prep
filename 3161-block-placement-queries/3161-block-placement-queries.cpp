class FenwickTree {
public:
    vector<int> bit;

    FenwickTree(int n) {
        bit.assign(n + 1, 0);
    }

    void maximize(int idx, int val) {
        int n = bit.size();

        while (idx < n) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int ans = 0;

        while (idx > 0) {
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }

        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int LIMIT = min(50000, (int)queries.size() * 3);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(LIMIT);

        // Build final obstacle configuration
        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        FenwickTree bit(LIMIT + 2);

        // Initialize gaps
        auto it = obstacles.begin();

        while (next(it) != obstacles.end()) {
            int L = *it;
            int R = *next(it);

            bit.maximize(R, R - L);

            ++it;
        }

        vector<bool> ans;

        // Process queries in reverse
        for (int i = (int)queries.size() - 1; i >= 0; --i) {

            auto &q = queries[i];

            if (q[0] == 1) {

                int x = q[1];

                auto it = obstacles.find(x);

                int L = *prev(it);
                int R = *next(it);

                // removing x merges intervals
                bit.maximize(R, R - L);

                obstacles.erase(it);

            } else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int pre = *prev(it);

                bool ok =
                    (bit.query(pre) >= sz) ||
                    (x - pre >= sz);

                ans.push_back(ok);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};