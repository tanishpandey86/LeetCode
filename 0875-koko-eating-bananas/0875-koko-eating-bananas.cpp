class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            long long hoursNeeded = 0;
            for (int p : piles) {
                hoursNeeded += (p + mid - 1) / mid; // ceil(p / mid)
            }

            if (hoursNeeded <= h) {
                hi = mid;       // mid works, try slower
            } else {
                lo = mid + 1;   // too slow, speed up
            }
        }

        return lo;
    }
};