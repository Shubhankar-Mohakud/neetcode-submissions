class Solution {
public:
    int trap(vector<int>& height) {
        int lMax=0, rMax=0, water=0;
        int maxH=height[0], index=0;
        for(int i=0; i<height.size(); i++){
            if(height[i]>maxH){
                maxH=height[i];
                index=i;
            }
        }
        for(int i=0; i<index; i++){
            if(lMax>height[i]) water += lMax-height[i];
            else lMax=height[i];
        }
        for(int i=height.size()-1; i>index; i--){
            if(rMax>height[i]) water += rMax-height[i];
            else rMax=height[i];
        }
        return water;
    }
};
