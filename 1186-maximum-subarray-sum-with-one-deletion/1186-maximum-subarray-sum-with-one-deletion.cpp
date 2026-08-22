class Solution {
public:
    int maximumSum(vector<int>& arr) {
       int n =arr.size();
       int noDel = arr[0];
       int oneDel = INT_MIN;
       int res = arr[0];

       for(int i=1;i<n;i++){
        int prevnoDel = noDel;
        int prevoneDel = oneDel;

        noDel= max(noDel + arr[i],arr[i]);

        int v2;
        if(prevoneDel == INT_MIN)
             v2=arr[i];
             else v2= prevoneDel+arr[i];

             oneDel = max(v2,prevnoDel);

             res = max(res,max(oneDel,noDel));
       }
       return res;
}



    
};