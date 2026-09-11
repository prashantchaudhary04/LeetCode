class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        int cs=nums[0]+nums[1]+nums[2];

        while(i<n-2){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];

                if(abs(sum-target)<abs(cs-target)){
                    cs=sum;
                }

                if(sum==target){
                    return sum;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
            i++;
        }

        return cs;
    }
};