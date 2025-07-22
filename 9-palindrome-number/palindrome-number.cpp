class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0;
        int n = s.length();
        while(i<n){
           if(s[i] != s[n-i-1])
           return false;

           i++; 
        }
        return true;
    }
};