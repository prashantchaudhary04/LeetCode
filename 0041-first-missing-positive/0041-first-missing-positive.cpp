class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        vector<bool>check(n+1 , false);
       
        for(int x : nums){
            if(x>0 && x<=n){
                check[x]=true;
            }
            
        }

        for(int i=1 ; i<=n ; i++){
            if(!check[i]){
                return i;
            }

        }  
        return n+1;
    }
};