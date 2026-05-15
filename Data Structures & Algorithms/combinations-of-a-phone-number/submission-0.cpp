class Solution {
public:
    map<char,string> mp;

    void solve(vector<string> &ans,string digits, string temp, int index){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<mp[digits[index]].size(); i++){
            solve(ans, digits, temp+mp[digits[index]][i], index+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string> ans;
        solve(ans, digits, "", 0);
        return ans;
    }
};
