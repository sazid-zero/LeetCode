class Solution {
public:
    string intToRoman(int num) {
        string s = "";

            int count = 0;

            if(num>=1000){
                count = num/1000;
                num = num%1000;
                s += string(count, 'M');
                count = 0;
            }

            if(num>=500){

                if(num >= 900){
                s+= "CM";
                 num = num%900;
                }

                
                else{
                num = num%500;
                s += 'D';
                }
            }
            if(num>=100){
                if(num >= 400){
                s+= "CD";
                 num = num%400;
                }
                else{
                count = num/100;
                num = num%100;
                
                s += string(count, 'C');
                count = 0;
                }
            }

            if(num>=50){
                if(num >= 90){
                s+= "XC";
                 num = num%90;
                }
                else{
                num = num%50;
                s += 'L';
                }
            }

            if(num>=10){

                if(num >= 40){
                s+= "XL";
                 num = num%40;
                }
                else{
                count = num/10;
                num = num%10; 
                s += string(count, 'X');
                count = 0;
                }
            }

            if(num>0){
                if(num == 9)
                s+="IX";
                else if(num==4)
                s+="IV";
                else if(num == 5)
                s+='V';
                else if(num==1)
                s+='I';
                else if(num>5){
                    s+='V';
                    num -= 5;
                    count = num/1;
                    s+=string(count, 'I');
                }

                else{
                count = num/1;
                
                s+=string(count, 'I');
                }
            }

            return s;
    }
};