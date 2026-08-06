class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long long totalGas = 0, totalCost = 0;
        for (int x : gas) totalGas += x;
        for (int x : cost) totalCost += x;
        if (totalGas < totalCost) return -1;

        int start = 0, tank = 0;
        for (int i = 0; i < (int)gas.size(); ++i) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }
};