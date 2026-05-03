class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int index=0;
        int carry=0;
        while(index<a.size() || index<b.size() || carry){
            int n1=0;
            if(index<a.size()){
                n1 = a[index]-'0';
            }
            int n2=0;
            if(index<b.size()){
                n2 = b[index]-'0';
            }
            int sum = n1+n2+carry;
            int digit = sum%2;
            carry = sum/2;
            ans.push_back((char)digit+'0');
            index++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};