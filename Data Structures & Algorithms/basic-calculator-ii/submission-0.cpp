class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int current = 0;
        char lastOp = '+';
        int i = 0;
        while (i < s.length()) {
            if (s[i] >= '0' && s[i] <= '9') {
                current = current * 10 + (s[i] - '0');
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i==s.length()-1) {
                if (lastOp == '+') {
                    st.push(current);
                } else if (lastOp == '-') {
                    st.push(-1 * current);
                } else if (lastOp == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(current * top);
                } else if (lastOp == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / current);
                }

                lastOp = s[i];
                current = 0;
            } 
            i++;
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};