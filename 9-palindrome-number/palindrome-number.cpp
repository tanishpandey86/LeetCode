class Solution {
public:
    bool isPalindrome(int x) {
        long int rev=0;
        int temp, fun=x;
        if (x<0)
            return false;
        while(x!=0){
            temp=x%10;
            rev=rev*10+temp;
            x=x/10;
        }
        return fun==rev;
    }
};