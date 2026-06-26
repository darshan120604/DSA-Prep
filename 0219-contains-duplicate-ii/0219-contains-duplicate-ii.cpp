#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        // Map to store: [number -> its last seen index]
        std::unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if the number already exists in our map
            if (mp.count(nums[i])) {
                // If the distance between current index and last index is <= k
                if (i - mp[nums[i]] <= k) {
                    return true;
                }
            }
            // Always update the map with the latest index of this number
            mp[nums[i]] = i;
        }
        
        return false;
    }
};
