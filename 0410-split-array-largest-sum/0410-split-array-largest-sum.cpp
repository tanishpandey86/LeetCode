class Solution {
public:
    long long subarray(vector<int> &nums,int k){
        int sub = 1;
        int k_sum = 0;
        for (int i = 0;i<nums.size();i++){
            if(k_sum + nums[i]<=k){
                k_sum +=nums[i];
            }
            else{
                sub++;
                k_sum=nums[i];
            }
        }
        return sub;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = (low+high)/2;
            int no = subarray(nums,mid);
            if(no>k) low=mid+1;
            else{
                high=mid-1;
            }
        }
        return low;
    }
};