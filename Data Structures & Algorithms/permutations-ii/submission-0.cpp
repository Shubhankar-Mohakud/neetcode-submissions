class Solution {
public:
    void permute(vector<int>& nums, vector<vector<int>> &ans, int index){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        vector<bool> used(21, 0);
        for(int i=index; i<nums.size(); i++){
            if(used[10+nums[i]]==0){
                swap(nums[i], nums[index]);
                permute(nums, ans,index+1);
                swap(nums[i], nums[index]);
                used[10+nums[i]] = true;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums, ans, 0);
        return ans;
    }
};