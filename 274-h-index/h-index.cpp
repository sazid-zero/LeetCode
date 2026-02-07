class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxVal = 0;
        for(int i=0; i<=1000; i++){
            int h = i;
            int p = 0;
            for(int j=0; j<citations.size(); j++)
            {   
                if(citations[j] >= h)
                p++;
            }

            if(p>=h)
            maxVal = max(maxVal,h);
            
        }
        return maxVal;
    }
};