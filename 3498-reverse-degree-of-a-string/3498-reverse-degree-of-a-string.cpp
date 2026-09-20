class Solution {
public:
    int reverseDegree(string s) {
        int count=1;
        int ans=0;
        for(char ch : s){
            int temp=ch-'a';
            temp=(26-temp);
            ans+=(temp*count);
            count++;
        }
        return ans;
    }
};