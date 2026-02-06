class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(auto x: nums)
        st.insert(x);
        copy(st.begin(), st.end(), nums.begin());
        return st.size();
    }
};