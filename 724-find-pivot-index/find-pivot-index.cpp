class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rightsum =0;
        int leftsum =0;
        for (int i=0;i<n;i++){
            rightsum+=nums[i];
        }
        for (int j=0;j<n;j++){
            rightsum-=nums[j];
            if(leftsum==rightsum){
                return j;
            }
            else{
                leftsum+=nums[j];
            }
        }
        return -1;
    }
};