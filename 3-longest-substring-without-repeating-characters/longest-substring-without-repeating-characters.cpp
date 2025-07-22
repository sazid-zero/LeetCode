class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int>v;
        v.push_back(0);
        
        for(int i = 0; i<s.length();){
            set<char>a;

            for(int j = i; j < s.length(); j++){
                if(a.find(s[j])!=a.end()){
                    v.push_back(a.size());
                    goto end;
                }
                else{
                    a.insert(s[j]);
                }
            }
            v.push_back(a.size());
            end: i++;
        }
        sort(v.begin(), v.end());
        return v[v.size()-1];

    }
};