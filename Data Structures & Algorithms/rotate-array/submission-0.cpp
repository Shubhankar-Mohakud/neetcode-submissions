class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<k; i++){
            int store = nums[n-1];
            for(int j=n-1; j>-1; j--){
                nums[j]=nums[j-1];
            }
            nums[0]=store;
        }
    }
};