class Solution {
public:
    string minWindow(string s, string t) {
       int low=0;
       int high=0;
       int n=s.size();
       int res=INT_MAX;
       int start=0;
       unordered_map<char,int> need;
       unordered_map<char,int> f;

       for(char c:t) need[c]++;
       int required= need.size();
       int formed =0;

       for(high=0;high<n;high++){
        f[s[high]]++;
        if(need.find(s[high])!=need.end()&& f[s[high]]==need[s[high]]){
            formed++;
        }
        while(formed==required){
            int len=high-low+1;
            if(len<res){
                res=len;
                start=low;
            }
            if(need.find(s[low])!=need.end()&& f[s[low]]==need[s[low]]){
                formed--;
        }
        f[s[low]]--;
        low++;
       }
       }
       if(res==INT_MAX) return "";
       return s.substr(start,res);
    }
};