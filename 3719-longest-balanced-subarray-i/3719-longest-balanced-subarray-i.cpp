// class Solution {
// public:
//     int longestBalanced(vector<int>& arr) {
//         unordered_map<int,int> evenfreq, oddfreq;
//         int n = arr.size();
//         int left = 0;
//         int ans = 0;
        
//         for(int right = 0; right < n; right ++){
//             if(arr[right] % 2 == 0){
//                 evenfreq[arr[right]]++;
//             } else {
//                 oddfreq[arr[right]]++;
//             }

//             while(oddfreq.size() != evenfreq.size()){
//                 if(arr[left] % 2 == 0){
//                     evenfreq[arr[left]]--;
//                     if(evenfreq[arr[left]] == 0){
//                         evenfreq.erase(arr[left]);
//                     }
//                 } else {
//                     oddfreq[arr[left]]--;
//                     if(oddfreq[arr[left]] == 0){
//                         oddfreq.erase(arr[left]);
//                     }
//                 }
//                 left++;
//             }

//             ans = max(ans, right - left + 1);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int longestBalanced(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<int,int> evenfreq, oddfreq;

            for(int j = i; j < n; j++) {
                if(arr[j] % 2 == 0)
                    evenfreq[arr[j]]++;
                else
                    oddfreq[arr[j]]++;

                if(evenfreq.size() == oddfreq.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
