// https://www.interviewbit.com/problems/minimum-difference-subsets/



// Impoprtant good question

int Solution::solve(vector<int> &A) {
    int n = A.size();

    // This is like subset sum problem
    int total = 0;
    for(int &vl : A) total += vl;

    vector<vector<bool>> dp(n + 1, vector<bool>(total + 5, false));

    for(int i = 0; i <= n; i++) dp[i][0] = true;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < total + 2; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j >= A[i - 1]) {
                dp[i][j] = dp[i][j] | dp[i - 1][j - A[i - 1]];
            }
        }
    }

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= total; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << " N ";
    // }

    int ans = total;

    for(int i = total; i >= 0; i--) {
        if (dp[n][i]) {
            ans = min(ans, abs(total - 2 * i));
        }
    }

    return ans;
}
