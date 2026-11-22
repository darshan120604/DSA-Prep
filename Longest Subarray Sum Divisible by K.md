## 01. Longest Subarray Sum Divisible by K

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1)

### Problem Description

**Task:** Given an array arr[] and a positive integer k, find the length of the longest subarray whose sum is divisible by k.Note: If there is no subarray with sum divisible by k, then return 0.Examples:Input: arr[] = [2, 7, 6, 1, 4, 5], k = 3

#### Examples

##### Example 1

- **Output:**
```text
2
```
- **Explanation:** The subarray is [2, -2] has sum = 0, which is divisible by 2.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(min(n, k))

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-22 10:29:21
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        
        unordered_map<int, int>firstseen;
        
        firstseen[0] = -1;
        long long prefix = 0;
        int ans = 0;
        
        
        for(int i = 0; i<arr.size(); i++){
            prefix += arr[i];
            
            int rem = ((prefix % k) + k) % k;
            
            if(firstseen.find(rem) != firstseen.end()){
                ans = max(ans, i-firstseen[rem]);
            }
            else{
                firstseen[rem] = i;
            }
        }
        
        return ans;
        
    }
};
```

*Generated on: 22/11/2026, 10:29:54*