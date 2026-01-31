class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char sm = 'z';
        bool swap = false;
        for(int i = 0;  i< letters.size(); i++){
            if((letters[i] > target) && (sm >= letters[i])){
                swap = true;
                sm = letters[i];
            }
        }

        if(!swap){
            return letters[0];
        }

        return sm;
    }
};