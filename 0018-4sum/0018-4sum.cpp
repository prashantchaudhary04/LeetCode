class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 
        
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
            
            
            long left = j + 1, right = n - 1;
            long targetSum = (long)target - nums[i] - nums[j]; 
            
            while (left < right) {
                long sum = nums[left] + nums[right];
                
                if (sum == targetSum) {
                    result.push_back({nums[i], nums[j], nums[(int)left], nums[(int)right]});
                    left++;
                    right--;
                    
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < targetSum) {
                    left++;  
                } else {
                    right--; 
                }
            }
        }
    }
    return result;
}
};