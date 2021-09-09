int soll(vector<int> &H, int i, int X, int Y) {
    if (i < 0) return 0;

    int res = 0;

    int v1, v2, v3;

    // Try for X
    if (H[i] <= X) v1 = 1 + recurr(H, i - 1, X - H[i], Y, dp);
    else v1 = 0;

    // Try for Y
    if (H[i] <= Y) v2 = 1 + recurr(H, i - 1, X, Y - H[i], dp);
    else v2 = 0;

    // Put in none
    v3 = recurr(H, i - 1, X, Y, dp);

    // max of v1, v2, v3

    return res;
}