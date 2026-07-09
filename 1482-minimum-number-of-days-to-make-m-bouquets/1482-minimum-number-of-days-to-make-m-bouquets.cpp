class Solution {
public:
    bool canMake(vector<int>& bloomDay, int k, int m, int day) {
        long long bouquets = 0;
        int adjacent = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                adjacent++;
                if (adjacent == k) {
                    bouquets++;
                    adjacent = 0;
                }
            } else {
                adjacent = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(bloomDay, k, m, mid)) {
                hi = mid;       // mid works, try smaller
            } else {
                lo = mid + 1;   // mid too small, need more days
            }
        }
        return lo;
    }
};