class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> M;
        for(int i=0; i<nums.size(); i++){
            M[nums[i]]++;
        }
        auto it = M.begin();
        while(it != M.end()){
            if(it->second > nums.size()/2) return it->first;
            it++;
        }
        return 0;
    }
};