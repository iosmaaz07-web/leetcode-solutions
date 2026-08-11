class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n=nums.size();
       int i=0;
       int res=1;
       int j=1;

       while(j<n){
        if(nums[j-1]==nums[j]){
            j++;
            continue;
        }
        nums[i+1]= nums[j];
            j++;
            res++;
            i++;
        
       }
       return res;
    }
};