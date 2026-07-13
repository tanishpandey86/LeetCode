class Solution {
public:

    bool canweplace(vector <int> &position,int n,int m){
        int cnt = 1;
        int last = position[0];
        for (int i = 1;i<position.size();i++){
            if(position[i]-last>=n){
                cnt++;
                last = position[i];
            }
        }
        if(cnt>=m) return true;
        else{
            return false;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int ans = -1;
        int n = position.size();
        int low = 0;
        int high = position[n-1]-position[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canweplace(position,mid,m)==true){
                int ans = mid;
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};