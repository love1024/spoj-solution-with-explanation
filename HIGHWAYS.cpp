#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

//Dijkstra algorithm using stl
int dijkstra(vector< vector< pii > > &vec,int u,int v,int n) {
    priority_queue< pii , vector<pii>, greater<pii> > que;

    long long cost[n+1];
    for(int i=0;i<n+1;i++)
        cost[i] = INT_MAX;

    cost[u] = 0;
    que.push(pii(u,0));

    while(!que.empty()) {
        pii p = que.top();
        int e = p.first,c = p.second;
        que.pop();

        for(int i=0;i<vec[e].size();i++) {
            pii cur = vec[e][i];

            if(c+cur.second < cost[cur.first]) {
                cost[cur.first] = c + cur.second;
                que.push(pii(cur.first,cost[cur.first]));
            }
        }
    }
    if(cost[v] == INT_MAX)
        cout<<"NONE"<<endl;
    else
        cout<<cost[v]<<endl;
}

int main() {

    //Take test cases run Dijkstra algorithm;
    int t,n,m,u,v,x,u1,v1,c;
    cin>>t;

    while(t--) {
        cin>>n>>m>>u>>v;

        vector< vector< pii > > vec(n+1);

        for(int i=0;i<m;i++) {
            cin>>u1>>v1>>c;
            vec[u1].push_back( pii(v1,c));
            vec[v1].push_back( pii(u1,c));
        }

        dijkstra(vec,u,v,n);
    }
}
