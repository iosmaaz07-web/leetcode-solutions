class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> temp;

        bool flag = false;

        for(int i=0;i<n;i++){
            if(flag == false && newInterval[0] <intervals[i][0]){
                temp.push_back(newInterval);
                flag = true;
            }
            temp.push_back({intervals[i][0],intervals[i][1]});
        }

        if(flag == false){
            temp.push_back(newInterval);
        }

        vector<vector<int>> res;
        int start1 = temp[0][0];
        int end1 = temp[0][1];

        for(int i=1;i<temp.size();i++){
            int start2 = temp[i][0];
            int end2 = temp[i][1];

            if(end1 >= start2){
                start1 = start1;
                end1 = max(end1,end2);
            }else{
                res.push_back({start1,end1});
                start1 = start2;
                end1 = end2;
            }
        }

        res.push_back({start1,end1});
        return res;
    }

};