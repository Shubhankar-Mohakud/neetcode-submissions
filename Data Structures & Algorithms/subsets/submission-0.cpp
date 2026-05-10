class Solution {
public:
    void subseq(vector<int> &nums, int index, int size, vector<vector<int>> &ans, vector<int> temp){
        if(index==size){
            ans.push_back(temp);
            return;
        }
        // not included
        subseq(nums, index+1, size, ans, temp);
        temp.push_back(nums[index]);
        subseq(nums, index+1, size, ans, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int size=nums.size();
        subseq(nums, 0, nums.size(), ans, {});
        return ans;
    }
};