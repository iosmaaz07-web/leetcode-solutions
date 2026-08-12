class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        for(auto e:nums){
            if( val !=e){
                nums[i]=e;
                i+=1;
            }
        }
        return i;
    }
};