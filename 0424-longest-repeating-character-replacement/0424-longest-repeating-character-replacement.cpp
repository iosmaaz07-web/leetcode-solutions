class Solution {
public:
    int characterReplacement(string s, int k) {
      int low=0;
     
      int res=0;
     
     
      int maxcount=0;
      int n =s.size();

      int count[256] ={0};
      for(int high=0;high<n;high++){
        count[(unsigned char)s[high]]++;
        maxcount =max(maxcount,count[(unsigned char)s[high]]);
        int len = high-low+1;
        int diff = len-maxcount;

        while(diff>k){
            count[(unsigned char)s[low]] --;
            low++;
            len = high-low+1;
             diff = len-maxcount;
        }
        
        res = max(res,len);
      }
      return res;
    }
};