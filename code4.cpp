//clear adj and visited vector declared globally after each test case
//check for long long overflow
//while adding and subs check if mod becomes -ve
//while using an integer directly in a builtin function add ll
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Dont keep array name as size or any other key word
//ctrl+end - to break infinite loop in sublime text
 
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;  
#define Fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define ll long long int
#define fo(i, a, b) for (long long int i = a; i <= b; i++)
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define newl cout<<"\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll inf = 1e9+7;
const ll mod = 1e9+7 ;
#define MAX 200005 

#define printv(ele) for(auto &vle : ele) cout << vle << " "; cout << "\n";

ll mini(ll a,ll b){
    if(a>=b)return b;
    return a;
}
 
ll maxi(ll a,ll b){
    if(a>=b)return a;
    return b;
}

void solve(){
    //write your code here
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll dp[n+2][3];//1 for R and 2 for B
    dp[0][1]=0;
    dp[0][2]=0;
    if(s[0]=='R') dp[0][2] = inf;
    if(s[0]=='B') dp[0][1] = inf;

    fo(i,1,n-1){
        if(s[i]=='?'){
            dp[i][1] = mini(1+dp[i-1][1],dp[i-1][2]);
            dp[i][2] = mini(1+dp[i-1][2],dp[i-1][1]);
        }else{
            if(s[i]=='R'){
                dp[i][1] = mini(dp[i-1][1]+1,dp[i-1][2]);
                dp[i][2] = inf;
                // if(dp[i-1][1]+1<dp[i-1][2])ans+='R';
                // else ans+='B';
            }else{
                dp[i][2] = mini(dp[i-1][1],dp[i-1][2]+1);
                dp[i][1] = inf;
                // if(dp[i-1][2]+1<dp[i-1][1])ans+='B';
                // else ans+='R';
            }
        }
    }

    for(auto &vlu : dp) {
        cout << vlu[2] << " ";
    }

    cout << "\n";


    for(auto &vlu : dp) {
        cout << vlu[1] << " ";
    }

    cout << "\n";

    string ans = "";
    ll mi;
    if(dp[n-1][1] < dp[n-1][2]) mi = 1;
    else mi=2;
    ll cur = n-1;
    while(cur>=0){
        if (mi == 1) ans+='R'; else ans+='B';

        if(dp[cur][mi]==dp[cur-1][3-mi]) mi = 3 - mi;
        cur--;
    }

    reverse(all(ans));
    cout << ans << "\n";
}   

int main(){

    w(T){
        solve();
    }
    return 0;
}