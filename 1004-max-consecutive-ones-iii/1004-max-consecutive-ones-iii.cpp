class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0,high=0, n=nums.size(),zerocount=0,res=INT_MIN;
        int len =0;
        while(high<n){
            if(nums[high]==0){
                zerocount++;
            }
            while(zerocount>k){
                if(nums[low]==0){
                 zerocount--;
                }
                low++;
               
            }
            
            int len= high-low+1;

            res = max(res,len);
            high++;
        }
return res;
    }
};