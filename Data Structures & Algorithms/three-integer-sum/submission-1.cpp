class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> ans={};
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = 0-nums[i];
            int start=i+1, end=n-1;
            while(start<end){
                int sum = nums[start]+nums[end];
                if(sum==target){
                    ans.push_back({nums[i], nums[start], nums[end]});

                    // Logic A (Safe & Single Step)
                    int low = nums[start], high = nums[end];
                    while (start < end && nums[start] == low) start++;
                    while (start < end && nums[end] == high) end--;
                }
                else if (sum>target) end--;
                else start++;
            }
        }
        return ans;
    }
};