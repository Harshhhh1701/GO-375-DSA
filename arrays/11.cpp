//trapping rain water -->total water in the space

class Solution {
public:
    int trap(vector<int>& height) {
        int land = 0;
        int maxi = 0;
        for(int i = 0; i < height.size(); i++) {
            land += height[i];
            maxi = max(maxi, height[i]);
        }

        int total = maxi * height.size();

        int air = 0;
        int localMax = 0;
        int i = 0;
        while(true) {
            if(height[i] > localMax) {
                air += (height[i] - localMax) * i;
                localMax = height[i];
            }
            if(localMax == maxi) {
                break;
            }
            i++;
        }

        localMax = 0;
        i = height.size() - 1;
        while(true) {
            if(height[i] > localMax) {
                air += (height[i] - localMax) * (height.size() - i - 1);
                localMax = height[i];
            }
            if(localMax == maxi) {
                break;
            }
            i--;
        }

        int water = total - land - air;

        return water;
    }
};