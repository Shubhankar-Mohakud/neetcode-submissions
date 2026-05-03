class Solution {
public:
    bool isValid(string s) {
        if(s.size()&1) return false;
        vector<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push_back(s[i]);
            }else if (s[i]==')' || s[i]==']' || s[i]=='}'){
                if(st.empty()) return false;

                if(s[i]==')'){
                    if(st[st.size()-1]=='(') st.pop_back();
                    else st.push_back(s[i]);
                }

                if(s[i]==']'){
                    if(st[st.size()-1]=='[') st.pop_back();
                    else st.push_back(s[i]);
                }

                if(s[i]=='}'){
                    if(st[st.size()-1]=='{') st.pop_back();
                    else st.push_back(s[i]);
                }
            }
        }
        cout<<st.size();
        return !(st.size());
    }
};
