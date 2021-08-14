#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 998244353 ;
const int N = 1e5 + 10 ;
vector<int> ser;

void solve(int x){

    queue<pair<int,int>> q ;
    q.push({0,0});

    while(ser.size() <= N){
        int sum = q.front().second;
        int cur = q.front().first;

        if(sum) ser.push_back(cur) ;
        q.pop() ;

        for(int i = 0 ; i < 10 ; i++){
        	if(sum == 0 && i == 0) continue ;

            if(sum + i*i <= x){
                q.push({(cur*10 + i) % mod , sum + i*i}) ;
            }
        }
    }
}

int32_t main(){
    int x ;
    cin >> x ;

    solve(x) ;

    for(int i = 0 ; i < 10 ; i++) cout << ser[i] << '\n' ;

    return 0;
}

