class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        int n=s.size();
        int res=0;
        unordered_map<char,int> f;

        for(high=0;high<n;high++){
            f[s[high]]++;
            int len = high-low+1;
            while(f.size()<high-low+1){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                   
                }
                low++;
            }
            if(f.size()==high-low+1){
                int len = high-low+1;
                res =max(len,res);
            }
        }
        return res;
    }
};