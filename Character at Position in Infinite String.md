## 01. Character at Position in Infinite String

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/the-infinite-string1049/1)

### Problem Description

**Task:** Given a string s and an integer pos, an infinite string is constructed by repeatedly applying the following operation. In the i-th step, append i consecutive $ characters, followed by the reverse of the current string, to the current string.Formally, if the current string is s, update it as:s = s + ('$' repeated i times) + reverse(s)The initial string is the given s, and the process continues indefinitely. Find and return the character at the pos(1-based indexing) in the resulting infinite string.Examples:Input: s = "12345", pos = 3

#### Examples

##### Example 1

- **Output:**
```text
3
```
- **Explanation:** In "12345...", the character at pos 3 is 3.

##### Example 2

- **Input:**
```text
s = "12345", pos = 10
```
- **Output:**
```text
2
```
- **Explanation:** In "12345$54321...", the character at pos 10 is 2.

##### Example 3

- **Input:**
```text
s = "abc", pos = 7
```
- **Output:**
```text
a
```
- **Explanation:** In "abc$cba...", the character at pos 7 is a.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log (pos))
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-23 06:54:10
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    char posInfinite(string &s, int pos) {
        long long n = s.size();
        long long len = n;
        long long i = 0;

        while (len < pos) {
            i++;
            len = 2 * len + i;
        }

        while (i > 0) {
            long long prev_len = (len - i) / 2;

            if (pos <= prev_len) {
                // In the first half: pos stays the same
            } 
            else if (pos <= prev_len + i) {
                // In the middle '$' section
                return '$';
            } 
            else {
                // In the reversed second half: mirror the position
                long long offset = pos - (prev_len + i);
                pos = prev_len - offset + 1;
            }

            len = prev_len;
            i--;
        }

        // Step 3: pos is now within the initial string 's' (1-based indexing)
        return s[pos - 1];
    }
};
```

*Generated on: 23/11/2026, 06:54:38*