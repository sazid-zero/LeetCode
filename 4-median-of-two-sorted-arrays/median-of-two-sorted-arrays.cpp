class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> s;

        for(auto a : nums1)     
        s.push_back(a);

        for(auto a : nums2)
        s.push_back(a);

        sort(s.begin(), s.end());

        int l = s.size();
        double ans;

        if(l%2==0){

            ans = (s[l/2] + s[(l/2)-1])/2.0;

        }
        else{
            ans = s[l/2]*1.0 ;
        }

        return ans;

        
    }
};