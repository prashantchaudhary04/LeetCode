class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(auto& num : nums){
            num=num*num;
        }

        sort(nums.begin(), nums.end());
        long long ans=0;


        for(int i=0 ; i<n ; i++){
            if(i<n/2){
                ans=ans-nums[i];
            }
            else{
                ans=ans+nums[i];
            }
        }


        return ans;
    }
};