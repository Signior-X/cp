

def rec(H, i, X, Y):
	if i < 0: return 0;

	if (dp[i][X][Y] != -1) return dp[i][X][Y]

	ans = 0;
	if (H[i] <= X)
		ans = max(ans, rec(H, i - 1, X - H[i], Y))

	if (H[i] <= Y)
		ans = max(ans, rec(H, i.- 1, X, Y - H[i]))

	ans = max(ans, rec(H, i - 1, X, Y))

	dp[i][X][Y] = ans
	return ans


rec(H, n - 1, X, Y)