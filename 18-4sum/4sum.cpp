class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       int n =  nums.size() ; 
        vector<vector<int>>ans;

        sort(nums.begin() , nums.end()) ; 

        for( int i=0 ; i<n-3 ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue ;
//i and j are fixed. The two remaining elements are picked from nums[j+1 ... n-1]. Since the array is sorted, the smallest two you could possibly pick are nums[j+1] and nums[j+2] 
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if ((long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;

            for ( int j=i+1 ; j<n-2 ; j++){
                if( j>i+1 && nums[j] == nums[j-1]) continue ;
            
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break ;
                if ((long long)nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;


                long long sum = (long long) target - nums[i] - nums[j]  ; 

                long long start=j+1 , end = n-1 ;

                while ( start < end ) {

                    if(nums[start] + nums[end] == sum){
                        ans.push_back({ nums[i] , nums[j] , nums[start] , nums[end] }) ;
                        start++ ;
                        end-- ;
                        while( start<end && nums[start] == nums[start-1] ) start++ ;
                        while( start<end && nums[end] == nums[end+1]) end-- ;
                    }
                    else if( nums[start] + nums[end] < sum ){
                        start++ ;
                    }
                    else {
                        end-- ; 
                    }
                }
            }
        }
        return ans ; 
    }
};