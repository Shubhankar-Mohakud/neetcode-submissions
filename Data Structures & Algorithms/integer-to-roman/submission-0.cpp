class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> mp = {
            {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, 
            {"X", 10},{"XL", 40}, {"L", 50}, {"XC", 90},
            {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}
        };
        string ans = "";
        int n = mp.size()-1;
        for(int i=n; i>-1; i--){
            if(num / mp[i].second){
                int count = num / mp[i].second;
                while(count--) ans.append(mp[i].first);
            }

            num %= mp[i].second;
        }
        return ans;
    }
};