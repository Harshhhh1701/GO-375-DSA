//11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=INT_MIN;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int shortline=min(height[left],height[right]);
            maxArea=max(maxArea,shortline*(right-left));
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};