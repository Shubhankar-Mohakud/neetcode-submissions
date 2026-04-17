class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] += 1;
        }
        map<int, int>::iterator it = mp.begin();
        while(it!=mp.end()){
            if(it->second>1){
                return true;
            }
            it++;
        }
        return false;
    }
};
