class Solution {
public:
int minSubArrayLen(int target , vector<int>& nums){
    int n = nums.size();
    int low,high=0;
    int res=INT_MAX;
    
    int sum=0;

    for(high=0;high<n;high++){
       sum=sum+nums[high];

       while(sum>=target){
        int len=high-low+1;
        res = min(res,len);

        sum=sum-nums[low];
        low++;
       }
    }
    if(res==INT_MAX){
        return 0;
    }
      return res;
    } 
};