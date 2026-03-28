class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n)
            return "";

        vector<int> hash(256, 0);
        for (char c : t) {
            hash[c]++;
        }

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int sIndex = -1, cnt = 0;

        while (r < m) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;

            while (cnt == n) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};