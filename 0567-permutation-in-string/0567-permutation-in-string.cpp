class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> need(26, 0), window(26, 0);
        for (char c : s1) need[c - 'a']++;
        for (int i = 0; i < n; i++) window[s2[i] - 'a']++;

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (need[i] == window[i]) matches++;
        }

        if (matches == 26) return true;

        for (int i = n; i < m; i++) {
            int add = s2[i] - 'a';
            int remove = s2[i - n] - 'a';

            // Add new character
            if (need[add] == window[add]) matches--;
            window[add]++;
            if (need[add] == window[add]) matches++;

            // Remove old character
            if (need[remove] == window[remove]) matches--;
            window[remove]--;
            if (need[remove] == window[remove]) matches++;

            if (matches == 26) return true;
        }

        return false;
    }
};