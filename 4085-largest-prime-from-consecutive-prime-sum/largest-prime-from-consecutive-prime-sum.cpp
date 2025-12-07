class Solution {
public:
    int largestPrime(int n) {
        const int MAXN = n;
        vector<char> prime(MAXN + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= MAXN; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= MAXN; j += i)
                    prime[j] = false;
            }
        }
        int currSum = 0;
        int ans = 0;

        for (int i = 2; i <= n; i++) {
            if (!prime[i]) continue;
            if (currSum + i > n)
                break;
            currSum += i;
            if (currSum <= n && prime[currSum])
                ans = currSum;
        }

        return ans;
    }
};