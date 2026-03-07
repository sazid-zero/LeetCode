class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> v;
        string r = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                if(!r.empty())
                v.push_back(r);
                r = "";
            }
            else if(i == s.size()-1){
                r+=s[i];
                v.push_back(r);
            }

            else r+=s[i];
        }
        int length = v[v.size()-1].size();
        return length;
    }
    
};