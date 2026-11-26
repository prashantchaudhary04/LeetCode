class Solution {
public:
    bool canAliceWin(int n) {
        int alice=0;
        int m=10;
        while(n>=m){
            n=n-m;
            alice=!alice;
            m--;
        }

        return alice==1;
        
    }
};