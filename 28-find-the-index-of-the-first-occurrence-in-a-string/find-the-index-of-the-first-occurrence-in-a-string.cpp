class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = needle.length();

    for(int j = 0; j<haystack.length(); j++ ){
        string s = "";
        for(int i = j; i<j+n && i<haystack.length(); i++){
            s+=haystack[i];
        }
        if(s == needle)
        return j;
    }

    return -1;
    }
};