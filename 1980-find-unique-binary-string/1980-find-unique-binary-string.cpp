class Solution {
public:
    int todec(string s){
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            ans <<= 1;          
            if (s[i] == '1') {  
                ans |= 1;       
            }
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,int> freq;
        for(int i =0; i< nums.size(); i++){
            int dec = todec(nums[i]);
            freq[dec]++;
        }
        string maxi = "";
        string low = "0";
        for(int i = 0; i<nums.size(); i++){
            maxi.push_back('1');
        }
        for(int i=1; i<nums.size(); i++){
            low.push_back('0');
        }
        int lowest = todec(low);
        int largest = todec(maxi);
        int miss;
        for(int i = lowest; i <= largest; i++){
            if(freq.find(i) == freq.end()){ // Corrected map lookup syntax
                miss = i;
                break;
            }
        }
        string res = "";
        for(int i = 0; i < nums.size(); i++) {
            res = ((miss & 1) ? "1" : "0") + res;
            miss >>= 1;
        }

        return res;
        
    }
};