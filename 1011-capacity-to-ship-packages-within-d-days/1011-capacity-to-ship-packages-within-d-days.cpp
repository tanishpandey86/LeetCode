class Solution {
public:
    long long possible(vector<int> &weights, int capacity){
        long long days = 1;
        long long currentLoad = 0;
        int n = weights.size();

        for (int i = 0; i < n; i++){
            if (currentLoad + weights[i] > capacity){
                days++;
                currentLoad = 0;
            }
            currentLoad += weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high){
            int mid = low + (high - low) / 2;

            if (possible(weights, mid) <= days){
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};