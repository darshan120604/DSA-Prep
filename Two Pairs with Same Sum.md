## 01. Two Pairs with Same Sum

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/satisfy-the-equation5847/1)

### Problem Description

**Task:** Given an array arr[] of positive integers, find four indices a, b, c, and d such that arr[a] + arr[b] = arr[c] + arr[d], where a, b, c, d are all distinct indices.If multiple such quadruplets exist, return the one that is lexicographically smallest when the indices are considered in the order a, b, c, d. If no such quadruplet exists, return {-1, -1, -1, -1}. Ensure a < b and c < d, and the pair (a, b) is lexicographically smaller than the pair (c, d).Examples:Input: arr[] = [3, 4, 7, 1, 2, 9, 8]

#### Examples

##### Example 1

- **Output:**
```text
[-1, -1, -1, -1]
```
- **Explanation:** No two distinct pairs of indices produce the same sum.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2)
- **Expected Auxiliary Space Complexity:** O(n^2)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-24 07:29:28
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        unordered_map<int, pair<int, int>> mp;
        vector<int> ans; 

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int sum = arr[i] + arr[j];

                if (mp.find(sum) == mp.end()) {
                    mp[sum] = {i, j};
                } 
                else {
                    int a = mp[sum].first;
                    int b = mp[sum].second;

                    if (a != i && a != j && b != i && b != j) {
                        vector<int> curr = {a, b, i, j};
                        if (ans.empty() || curr < ans) {
                            ans = curr;
                        }
                    }
                }
            }
        }

        if (ans.empty()) return {-1, -1, -1, -1};
        return ans;
    }
};
```

*Generated on: 24/11/2026, 07:30:01*