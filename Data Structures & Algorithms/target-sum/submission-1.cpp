class Solution {
public:
    int solve(vector<int>& nums, int target,int index,int sum){
        // base case
        if(index==nums.size()){
            if(sum==target) return 1;
            else return 0;
        }
        int ans=0;
        ans += solve(nums, target, index+1, sum-nums[index]);
        ans += solve(nums, target, index+1, sum+nums[index]);

        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};
