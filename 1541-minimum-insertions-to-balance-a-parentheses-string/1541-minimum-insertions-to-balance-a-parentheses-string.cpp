class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0;   // insertions needed
        int count = 0;    // unmatched '(' so far
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                count++;
                i++;
            } else {
                // we have a ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;          // found a full "))"
                } else {
                    result++;        // missing second ')', insert one
                    i++;
                }

                if (count > 0) {
                    count--;         // this "))" closes one '('
                } else {
                    result++;        // no '(' to match, insert one
                }
            }
        }
        return result + count * 2;   // each leftover '(' needs "))"
    }
};