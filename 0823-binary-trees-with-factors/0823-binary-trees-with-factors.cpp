class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<long long> dp(n, 1);
        unordered_map<int, int> valToIdx;
        for (int i = 0; i < n; ++i) {
            valToIdx[arr[i]] = i;
        }

        long long totalTrees = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (1LL * arr[j] * arr[j] > arr[i]) {
                    break;
                }

                if (arr[i] % arr[j] == 0) {
                    int rightVal = arr[i] / arr[j];
                    if (valToIdx.count(rightVal)) {
                        int k = valToIdx[rightVal];
                        if (arr[j] == rightVal) {
                            dp[i] = (dp[i] + dp[j] * dp[j]) % MOD;
                        } else {
                            dp[i] = (dp[i] + 2 * dp[j] * dp[k]) % MOD;
                        }
                    }
                }
            }
            totalTrees = (totalTrees + dp[i]) % MOD;
        }

        return totalTrees;
    }
};