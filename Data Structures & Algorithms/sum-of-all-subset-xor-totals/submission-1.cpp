class Solution {
public:
    void solve(vector<int>& nums, int index, int size, vector<int>& ans, int total){
        if(index==size){
            ans.push_back(total);
            return;
        }        
        solve(nums, index+1, size, ans, total);
        solve(nums, index+1, size, ans, total ^ nums[index]);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> ans;
        solve(nums, 0, nums.size(), ans, 0);
        int sum = 0;
        for(int i=0; i<ans.size(); i++) sum += ans[i];

        return sum;

    }
};