class Solution {
public:
    void solve(string& s, string& curr, int i, int count,
               int remL, int remR, unordered_set<string>& st) {
        if (count < 0 || remL < 0 || remR < 0) return;

        if (i == (int)s.size()) {
            if (count == 0 && remL == 0 && remR == 0) st.insert(curr);
            return;
        }

        char c = s[i];

        if (c != '(' && c != ')') {
            curr.push_back(c);
            solve(s, curr, i + 1, count, remL, remR, st);
            curr.pop_back();                      // backtrack
            return;
        }

        // Option 1: remove this bracket
        if (c == '(') solve(s, curr, i + 1, count, remL - 1, remR, st);
        else          solve(s, curr, i + 1, count, remL, remR - 1, st);

        // Option 2: keep this bracket
        curr.push_back(c);
        solve(s, curr, i + 1, count + (c == '(' ? 1 : -1), remL, remR, st);
        curr.pop_back();                          // backtrack
    }

    vector<string> removeInvalidParentheses(string s) {
        int remL = 0, remR = 0;
        for (char c : s) {
            if (c == '(') remL++;
            else if (c == ')') {
                if (remL > 0) remL--;
                else remR++;
            }
        }

        unordered_set<string> st;
        string curr = "";
        solve(s, curr, 0, 0, remL, remR, st);
        return vector<string>(st.begin(), st.end());
    }
};