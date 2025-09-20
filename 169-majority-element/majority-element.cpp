class Solution {
public:
    int majorityElement(vector<int>& v) {
        int cnt = 0;
        int el;
        
        // Phase 1: Find potential majority candidate
        for(int i = 0; i < v.size(); i++){
            if (cnt == 0){
                cnt = 1;
                el = v[i];
            }
            else if(v[i] == el){
                cnt++;
            }
            else {
                cnt--;
            }
        }
        
        // Phase 2: Verify the candidate (moved outside the loop)
        int cnt1 = 0;
        for (int i = 0; i < v.size(); i++){
            if(v[i] == el){
                cnt1++;
            }
        }
        
        if(cnt1 > v.size()/2){
            return el;
        }
        
        return -1;
    }
};
