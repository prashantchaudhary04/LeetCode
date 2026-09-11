class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int lm=height[left];
        int rm=height[right];

        int ans=0;

        while(left<right){
            if(lm < rm){
                left++;
                lm=max(lm, height[left]);
                ans+=(lm-height[left]);
            }
            else{
                right--;
                rm=max(height[right], rm);
                ans+=(rm-height[right]);
            }
        }

        return ans;
    }
};