class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       
    int cntOne = 0, cntZero = 0;
    int ans = 0;

    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] == 0)
            cntZero++;
        else
            cntOne++;

        int diff = cntZero - cntOne;

        if (diff == 0) {
            ans = max(ans, i + 1);
        }

        if (mp.find(diff) != mp.end()) {
            int idx = mp[diff];
            int len = i - idx;
            ans = max(ans, len);
        }
        else {
            mp[diff] = i;
        }
    }

    return ans;

    }
};