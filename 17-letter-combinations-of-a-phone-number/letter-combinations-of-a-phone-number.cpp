class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> v = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

        vector<string> vs;

        int n = digits.length();

        if(n <= 0)
        return vs;
        string first = n > 0 ? v[digits[0]] : "";
        string second = n > 1 ? v[digits[1]] : "";
        string third = n > 2 ? v[digits[2]] : "";
        string fourth = n > 3 ? v[digits[3]] : "";

        for(int i = 0; i<first.length(); i++){
            string s = "";
            s+= first[i];
            if(second!=""){
            for(int j = 0; j<second.length(); j++){
                s+=second[j];
                if(third!=""){
                    for(int k = 0; k<third.length(); k++){
                    s+=third[k];
                    if(fourth!=""){
                        for(int l = 0; l<fourth.length();l++){
                        s+=fourth[l];
                        vs.push_back(s);
                        s.pop_back();
                        if (l == fourth.length()-1){
                            s.pop_back();
                        goto end3;
                        }

                    }}
                    
                    vs.push_back(s);
                    s.pop_back();

                    end3:

                    if (k == third.length()-1){
                            s.pop_back();
                        goto end2;
                        }

                    
                    
                }
                }
                vs.push_back(s);
                s.pop_back();

                end2:
                if (j == second.length()-1){
                            s.pop_back();
                        goto end1;
                        }   
            }
            }
            
            vs.push_back(s);

            end1:

        }

        return vs;



    


    }
};