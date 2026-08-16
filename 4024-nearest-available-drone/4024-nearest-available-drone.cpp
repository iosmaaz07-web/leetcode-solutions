class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int bestIdx=-1;
        long long bestDist = LLONG_MAX;

        for(int i=0; i<drones.size(); i++){
            int x = drones[i][0];
             int y = drones[i][1];
             int range = drones[i][2];

             long long dist= abs((long long)x-target[0])+ abs((long long)y - target[1]);

             if(dist<=range && dist < bestDist){
                bestDist = dist;
                bestIdx = i;
             }
             
        }
        return bestIdx;
    }
};