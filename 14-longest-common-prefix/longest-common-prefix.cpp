class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Use: Vertical scanning
        int n = strs.size();
        string result = "";

        sort(strs.begin(), strs.end());
        int i = 0;
        int len = strs[0].length();
        while (i < len) {
            if (strs[0][i] == strs[n - 1][i]) {

                result += strs[0][i];
                i++;
            } else {
                break;
            }
        }
        return result;
    }
};