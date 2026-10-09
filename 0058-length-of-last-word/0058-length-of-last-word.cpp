class Solution {
public:
    int lengthOfLastWord(string s) {
        int n= s.length()-1 ;
        int count = 0;

        if(s[n] == ' '){
            while( n>=0 && s[n] == ' '){
                n--;
            }
        }
        while(n>= 0 && s[n] != ' '){
        

            n--;
            count++;
        }
        return count;
    }
};