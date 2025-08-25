class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int radius = 0;
        
        for (int house : houses) {
            // lower_bound to find the first heater >= house
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            
            int rightDist = (it == heaters.end()) ? INT_MAX : *it - house;
            int leftDist = (it == heaters.begin()) ? INT_MAX : house - *(it - 1);
            
            int nearest = min(leftDist, rightDist);
            radius = max(radius, nearest);
        }
        
        return radius;
    }
};