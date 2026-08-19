class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minEnding = nums[0];
        int maxEnding = nums[0];
        int res = nums[0];

        for(int i=1;i<n;i++){
            int v1 = nums[i];
            int v2 = minEnding*nums[i];
            int v3 = maxEnding*nums[i];

            maxEnding = max(v1,max(v2,v3));
            minEnding = min(v1,min(v2,v3));
            
            res = max(res,max(maxEnding,minEnding));
        }
        return res;
    }
};