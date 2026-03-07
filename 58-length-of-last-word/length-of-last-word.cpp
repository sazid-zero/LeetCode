class Solution {
public:
    int lengthOfLastWord(string s) {
        string r = "";
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == ' '){
                if(!r.empty())
                break;
            }
            else r+=s[i];
        }
        int length = r.size();
        return length;
    }
    
};