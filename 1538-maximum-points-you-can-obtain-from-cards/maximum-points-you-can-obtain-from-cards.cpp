class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += cardPoints[i];
        }
        int window = n - k;
        if (window == 0)
            return total;
        int l = 0, r = 0, sum = 0;
        while (r < window) {
            sum += cardPoints[r];
            r++;
        }
        int ans = total - sum;
        while (r < n) {
            sum = sum - cardPoints[l] + cardPoints[r];
            ans = max(ans, total - sum);
            r++;
            l++;
        }
        return ans;
    }
};