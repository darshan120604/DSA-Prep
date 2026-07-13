class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int m = to_string(low).size();
        int n = to_string(high).size();

        vector<string> s;

        while(m<=n || m<=9){
            string q = "";
            int i = 1;
            while(q.size()<m){
                q.push_back('0'+i);
                i++;
            }
            s.push_back(q);
            while(i<=9){
                q.erase(0,1);
                q.push_back('0'+i);
                i++;
                s.push_back(q);
            }
            if(q.size() == 9) break;
            m++;
        }
        vector<int> ans;
        for(int i = 0; i< s.size(); i++){
            if(low <= stoi(s[i]) && high >= stoi(s[i])){
                ans.push_back(stoi(s[i]));
            }
        }
        
        return ans;
    }
};