class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=0;
        int n=nums.size();

        while(right<n){
            if(nums[right]!=val){
                swap(nums[left], nums[right]);
                left++;
                right++;
            }
            else{
                right++;
            }
        }

        return left;
    }
};