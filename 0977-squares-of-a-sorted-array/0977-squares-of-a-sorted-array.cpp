class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int left=0;
        int right=n-1;
        int pos=n-1;

        while(left<=right){
            int ls=nums[left]*nums[left];
            int rm=nums[right]*nums[right];

            if(ls>rm){
                ans[pos]=ls;
                left++;
                pos--;
            }
            else{
                ans[pos]=rm;
                right--;
                pos--;
            }
        }
        return ans;
    }
};