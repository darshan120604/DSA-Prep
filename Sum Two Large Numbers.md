## 01. Sum Two Large Numbers

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1)

### Problem Description

**Task:** Given two strings denoting non-negative numbers s1 and s2. Calculate the sum of s1 and s2. Examples:Input: s1 = "25", s2 = "23"

#### Examples

##### Example 1

- **Output:**
```text
"5"
```
- **Explanation:** The sum of 2 and 3 is 5.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-23 16:02:09
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    string findSum(string &s1, string &s2) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string ans = "";

        // Traverse from right to left while digits or carry remain
        while (i >= 0 || j >= 0 || carry > 0) {
            int d1 = (i >= 0) ? s1[i--] - '0' : 0;
            int d2 = (j >= 0) ? s2[j--] - '0' : 0;

            int sum = d1 + d2 + carry;
            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        // Remove trailing zeros (which become leading zeros after reversing)
        while (ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

*Generated on: 23/11/2026, 16:02:43*