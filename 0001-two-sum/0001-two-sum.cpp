class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());  // sort arr, NOT nums

        int i = 0;
        int j = n - 1;

        while (i < j) {
            int sum = arr[i].first + arr[j].first;  // use arr, not nums
            if (sum == target) {
                return {arr[i].second, arr[j].second};  // return original indices
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};