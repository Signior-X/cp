#include <bits/stdc++.h>
using namespace std;

int mxsm(vector<vector<int>> A, int B) {
    int smr = 0;
    int ans = INT_MIN;
    for(int i = 0; i + B - 1 < A.size(); i++) {
        if (i == 0) {
            for(int a = 0; a < B; a++) {
                for(int b = 0; b < B; b++) {
                    // cout << A[a][b] << "\n";
                    smr += A[a][b];
                }
            }
        } else {
            // slide the window
            for(int j = 0; j < B; j++) {
                smr -= A[j][i - 1];
                smr += A[j][i + B - 1];
            }
        }

        cout << "smr: " << smr << "\n";
        ans = max(ans, smr);

        int smc = smr;

        // Now we will slide the column
        for(int j = 1; j + B - 1 < A.size(); j++) {
            // As first one already calculated
            // So, start from j = 1

            for(int k = 0; k < B; k++) {

                smc -= A[j - 1][k + i];
                smc += A[j + B - 1][k + i];

            }

            ans = max(ans, smc);

        }

    }

    return ans;

}

int main() {
	vector<vector<int>> q = {
        {-13, 70, 63, 1, 3, -77, 27},
        {-100, 69, -85, 65, -72, 43, 47},
        {-12, 43, -63, -91, -37, -51, -19},
        {88, 42, -92, -40, -79, 58, 54},
        {-12, 46, -10, 49, -57, -70, -80},
        {48, -33, 36, 83, -65, -74, 85},
        {-62, -47, -71, -76, 48, 23, 59}
    };

    int ans = mxsm(q, 2);
    cout << ans << "\n";

	return 0;
}