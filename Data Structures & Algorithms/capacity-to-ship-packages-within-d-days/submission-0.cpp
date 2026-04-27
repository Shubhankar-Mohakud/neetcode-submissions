class Solution {
public:
    int countDays(vector<int>& W, int maxW){
        int currW = 0;
        int days = 1;
        for(int i=0; i<W.size(); i++){
            if(currW + W[i]<=maxW){
                currW += W[i];
            } else{
                days++;
                currW = W[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start=INT_MIN, end=0, ans=-1, mid;

        for(int i=0; i<weights.size(); i++){
            start = max(start, weights[i]);
            end += weights[i];
        }
        while(start<=end){
            mid = start + (end-start)/2;

            int numDays = countDays(weights, mid);

            if(numDays<=days){
                ans=mid;
                end = mid-1;
            } else start = mid+1;
        }
        return ans;
    }
};