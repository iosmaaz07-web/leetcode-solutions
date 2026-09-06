class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n = nums.size();
      
      int sum = accumulate(nums.begin(),nums.end(),0);
      int left =0;
      for(int i=0;i<n;i++){
        
        int right = sum - nums[i]-left;
        if(left == right)
        return i;
        left += nums[i];
      }
      return -1;
    }
};