// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string ans = strs[0];
//         for(int i=1;i<strs.size();i++){
//             int j=0;
//             for(char s : strs[i]){
//                 if(s != ans[j]){
//                     ans= ans.substr(0,j);
//                     break;
//                 }
//                 j++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix = strs[0];

        // Iterate through the rest of the strings in the vector
        for (size_t i = 1; i < strs.size(); ++i) {
            // Trim the prefix until it is a prefix of the current string
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) {
                    return ""; // No common prefix found
                }
            }
        }

        return prefix;
    }
};
