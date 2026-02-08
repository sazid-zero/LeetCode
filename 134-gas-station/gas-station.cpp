class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int dif = 0;
        int tank = 0; 
        int start = 0; 
        
        for(int i = 0; i < n; i++){
            dif += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){ 
                tank = 0; 
                start = i + 1; 
            }
        }
        return (dif < 0) ? -1 : start;
    }
};