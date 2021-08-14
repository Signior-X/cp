#include <bits/stdc++.h>
using namespace std;


vector<string> prettyJSON(string A) {
    // brackets increase tab and enter
    // comma make \n

    vector<string> finalAns;
    string ans = "";

    string tbs = "";

    for(int i = 0; i < A.length(); i++) {

        if (A[i] == '{' || A[i] == '[') {
            ans = "";
            finalAns.push_back(tbs + A[i]);
            tbs += "\t";
            ans += tbs;
        } else if (A[i] == '}' || A[i] == ']'){

            if (ans.length()) {
                finalAns.push_back(ans);
            }
            ans = "";

            int tbsl = tbs.length();
            tbs = tbs.substr(0, tbsl - 1);
            
            if ( (i+1 < A.length()) && A[i + 1] == ',') {
                ans = tbs + A[i];
            } else {
                finalAns.push_back(tbs + A[i]);
            }

        } else if (A[i] == ',' || (A[i] == ':' && (A[i+1] == '{' || A[i+1] == '['))) {
            finalAns.push_back(ans + A[i]);
            ans = "";
            ans += tbs;
        } else {
            ans += A[i];
        }

    }

    return finalAns;
}


int main () {

    // https://www.interviewbit.com/problems/pretty-json/
    string st = "{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"},K: \"L\"}}";
    vector<string> ans = prettyJSON(st);

    for(string vl : ans) {
        cout << vl << "\n";
    }


    // One of the HARDEST
    // Done with some seeing the test cases
    // , after }
    // done myself, but still feel hard

    return 0;
}
