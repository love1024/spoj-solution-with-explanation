#include<bits/stdc++.h>

using namespace std;

//Range of nodes
#define MAX 105

//Graph
vector< vector< pair<int,int> > > graph(MAX);

//Distance from source node
int dist[MAX];


//Dijkstra algorithm
void dijkstra(int s) {

    priority_queue< pair<int,int> , vector< pair<int,int> > ,greater< pair<int,int> > > que;

    for(int i=0;i<MAX;i++)
        dist[i] = 100000000;

    que.push(pair<int,int>(s,0));
    dist[s] = 0;

    while(!que.empty()) {
        int v = que.top().first;
        que.pop();

        for(int i=0;i<graph[v].size();i++) {
            int n = graph[v][i].first,cost = graph[v][i].second;
            if(dist[v] + cost < dist[n]) {
                que.push(pair<int,int>(n,dist[v]+cost));
                dist[n] = dist[v] + cost;
            }
        }
    }
}

int main() {

    //Take variables
    int N,E,T,M;
    cin>>N>>E>>T>>M;

    //Take graph in reverse order as we will
    //start from exit node
    int u,v,cost;
    for(int i=0;i<M;i++) {
        cin>>u>>v>>cost;
        graph[v].push_back(pair<int,int>(u,cost));
    }

    //We wills start from exit node
    //and find distance of all nodes from here
    dijkstra(E);

    //If we can reach a node from exit node in time less than T
    int cnt = 0;
    for(int i=1;i<=N;i++) {
        if(dist[i] <= T)
            cnt++;
    }

    //print out the result
    cout<<cnt<<endl;
}
