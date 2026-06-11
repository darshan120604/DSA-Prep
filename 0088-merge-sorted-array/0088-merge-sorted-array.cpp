class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if( nums1[i]>nums2[j]){
                    int temp=nums1[i];
                    nums1[i]=nums2[j];
                    nums2[j]=temp;
                    
                }
            }
        
        }
        int k=0;
        for(int i=m;i<m+n;i++){ 
            nums1[i]=nums2[k];
    
            k++;
        }
        for(int i=m;i<m+n;i++){ 
            for(int j=i;j<m+n;j++){
                if(nums1[i]> nums1[j]){
                    int temp=nums1[i];
                    nums1[i]=nums1[j];
                    nums1[j]=temp;
                }
            }    
        }
    }
};