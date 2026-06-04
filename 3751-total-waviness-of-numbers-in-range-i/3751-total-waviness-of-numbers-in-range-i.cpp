class Solution {
public:
    int isWave(int n){
        vector<int> arr;
        while(n){
            arr.push_back(n%10);
            n/=10;
        }
        int cnt = 0;
        for(int i = 1; i< arr.size() - 1; i++){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) cnt++;
            if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) cnt++;
        }

        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i = num1; i<=num2; i++){
            cnt+=isWave(i);
        }
        return cnt;
    }
};