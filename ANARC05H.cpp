#include<bits/stdc++.h>

using namespace std;

int dp[32][256];

int solve(string &str,int i,int prev) {
    if(i == str.length())
        return 1;
    else if(dp[i][prev] != -1)
        return dp[i][prev];

    int sum = 0,cnt = 0;
    for(int j=i;j<str.length();j++) {
        sum += (str[j] - '0');
        if(sum >= prev) {
            cnt += solve(str,j+1,sum);
        }
    }
    dp[i][prev] = cnt;
    return cnt;
}

int main() {
    string str;
    cin>>str;

    int c = 1;
    while(str != "bye") {
        memset(dp,-1,sizeof(dp));
        cout<<c<<". "<<solve(str,0,0)<<endl;
        cin>>str;
        c++;
    }
}
