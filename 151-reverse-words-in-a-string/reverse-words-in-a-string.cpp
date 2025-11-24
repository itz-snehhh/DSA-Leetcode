class Solution {
public:
    // brute force
    string reverseWords(string s) {
        s += " ";
        string word = "";
        stack<string> st;
        for (char c: s) {
            if (c == ' ') {
                if (word != "") {
                    st.push(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        string ans = "";
        while (st.size() != 1) {
            ans += st.top() + " ";
            st.pop();
        }
        ans += st.top();
        return ans;
    }
};