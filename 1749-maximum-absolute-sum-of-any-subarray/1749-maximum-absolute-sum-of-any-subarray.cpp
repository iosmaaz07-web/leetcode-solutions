class Solution {
public:
    int maxSubArraySum(vector<int>& nums) {
        int n =nums.size();
        int bestending = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++){
            int v1 = (bestending + nums[i]);
            int v2 = nums[i];

            bestending = max(v1,v2);
            ans = max(ans,bestending);
        }
        return ans;
    }

    int minSubArraySum(vector<int>& nums) {
        int n =nums.size();
        int bestending = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++){
            int v1 = (bestending + nums[i]);
            int v2 = nums[i];

            bestending = min(v1,v2);
            ans = min(ans,bestending);
        }
        return ans;
    }
int maxAbsoluteSum(vector<int> & nums){
    int maxSum = maxSubArraySum(nums);
    int minSum = minSubArraySum(nums);
    return max(abs(maxSum),abs(minSum));
}

};
