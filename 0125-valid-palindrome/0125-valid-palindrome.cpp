class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        int st = 0;
        int end = filtered.size() - 1;
        while (st < end) {
            if (filtered[st++] != filtered[end--]) {
                return false;
            }
        }
        return true;
    }
};