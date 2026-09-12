class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ws=0;
        for(int i=0 ; i<k ; i++){
            ws+=nums[i];
        }

        double ms=ws;
        for(int i=k ; i<nums.size() ; i++){
            ws=ws+nums[i]-nums[i-k];
            ms=max(ms, ws);
        }

        return ms/k;
    }
};