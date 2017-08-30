#include<bits/stdc++.h>
using namespace std;int main(){int t,n,i,j;cin>>t;while(t--){cin>>n;int a[n+1][n+1];for(i=0;i<n;i++)for(j=0;j<i+1;j++)cin>>a[i][j];for(i=n-2;i>=0;i--)for(j=0;j<i+1;j++)a[i][j]+=max(a[i+1][j],a[i+1][j+1]);cout<<a[0][0]<<endl;}}
