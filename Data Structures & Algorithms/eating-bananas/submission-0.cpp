class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int start=1, end=piles[piles.size()-1], ans=-1, mid;
        while(start<=end){
            mid = start + (end-start)/2;
            long long hoursTaken = 0;
            for(int i=0; i<piles.size(); i++){
                if(piles[i]%mid!=0) hoursTaken += piles[i]/mid + 1;
                else hoursTaken += piles[i]/mid;
            }
            if(hoursTaken<=h){
                ans = mid;
                end = mid-1;
            } else start=mid+1;
        }
        return ans;
    }
};
