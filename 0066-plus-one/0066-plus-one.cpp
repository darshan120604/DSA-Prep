class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int i = 0;
        int j = 0;
        while(true){
            if(digits[i] < 9){
                digits[i]++;
                break;
            }else{
                digits[i++] = 0;
                j++;
                if(j == digits.size()){
                    break;
                }
            }
        }
        if(j == digits.size()){
            digits.push_back(1);
                
        }
       

        reverse(digits.begin(),digits.end());
        return digits;        
    }
};