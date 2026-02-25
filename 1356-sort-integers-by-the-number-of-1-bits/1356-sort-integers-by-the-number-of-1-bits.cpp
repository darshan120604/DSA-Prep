class Solution {
public:
    int countSetBits(int n){
        int count = 0;
        while(n > 0){
            n = n & (n-1);
            count++;
        }

        return count;
    }

    bool compare(int a, int b){
        int cntA = countSetBits(a);
        int cntB = countSetBits(b);
        if(cntA != cntB) return cntA < cntB;
        return a < b;
    }

    void quickSort(vector<int>& arr, int left, int right){
        if(left >= right) return;

        int pivot = arr[left + (right - left) / 2];
        int i = left, j = right;

        while(i<=j){
            while(compare(arr[i], pivot)) i++;
            while(compare(pivot, arr[j])) j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j) quickSort(arr, left, j);
        if (i < right) quickSort(arr,i,right);
    }

    vector<int> sortByBits(vector<int>& arr) {
        quickSort(arr, 0, arr.size()-1);
        return arr;
    }
};