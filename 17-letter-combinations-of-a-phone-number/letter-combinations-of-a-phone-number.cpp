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
        string first = "";
        string second = "";
        string third = "";
        string fourth = "";

        for(int i = 0; i<n; i++){
            if(i == 0)
            first = v.find(digits[i])->second;
            else if(i == 1)
            second = v.find(digits[i])->second;
            else if(i == 2)
            third = v.find(digits[i])->second;
            else if(i == 3)
            fourth = v.find(digits[i])->second;
        }

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