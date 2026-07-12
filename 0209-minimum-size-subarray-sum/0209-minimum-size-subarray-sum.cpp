class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
       int low =0;
       int high =0;
       int sum =0;
       int minLen= INT_MAX;

       while(high<n){
        sum+=nums[high];

        while(sum>=target){
            minLen = min(minLen,high-low+1);
            sum-=nums[low];
            low++;
        }
        high++;
       }
       return(minLen == INT_MAX)?0 : minLen;
    } 
};