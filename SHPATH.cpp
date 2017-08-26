#include<bits/stdc++.h>

using namespace std;

//Max number of nodes in graph
#define MAX 10005
#define pii pair<int,int>

//Graph adjacency list
vector< pair<int,int> > cities[MAX];

//Map to store cities names and index
map<string,int> mp;

//Dist to store distance of nodes from source
int dist[MAX];

//Dijkstra shortest path algorithm
void shortestPath(int src,int ed) {

    //Min heap to store graph (val and cost)
    priority_queue<pii,vector<pii>,greater< pii > > pq;

    //Push source in min heap
    pq.push(pii(0,src));

    //make distance of source node 0
    dist[src] = 0;

    //while heap is not empty
    while(!pq.empty()) {

        //take the node value
        int u = pq.top().second;

        //pop the min node
        pq.pop();

        //Traverse all the adjacent nodes of current node
        for(int i=0;i<cities[u].size();i++) {

            //Take the index of adjacent node
            int v = cities[u][i].second;

            //Take the cost of adjacent node
            int c = cities[u][i].first;

            //if the cost of adjacent node through this node
            //is minimum
            if(dist[u]+c < dist[v]) {

                //Make cost of this node minimum
                dist[v] = dist[u]+c;

                //Push the new node
                pq.push(pii(dist[v],v));
            }
        }
    }
}

int main() {

    //Take number of test cases
    int t,n,p,nr,cost,r;
    scanf("%d",&t);

    //Loop over all test cases
    while(t--) {

        //Take number of cities
        scanf("%d",&n);

        //Traverse all cities
        char str[20];
        for(int i=0;i<n;i++) {

            //Take city name and its neighbors
            scanf("%s%d",str,&p);

            //Insert city into map
            mp[str] = i+1;

            //Traverse all neighbors
            for(int j=0;j<p;j++) {

                //Take the neighbor value and cost
                scanf("%d%d",&nr,&cost);

                //Insert in graph
                cities[nr].push_back(pii(cost,i+1));
            }
        }

        //Take number of shortest path to search
        scanf("%d",&r);
        char s1[20],s2[20];

        //Find all shortest paths
        for(int i=0;i<r;i++) {

            //Take cities
            scanf("%s%s",s1,s2);

            //Find index of both cities
            int u = mp[s1];
            int v = mp[s2];

            //Initialize distance array to max
            for(int j=0;j<=n;j++)
                dist[j] = 1000000000;

            //Dijkstra shortest algorithm on starting node
            shortestPath(u,v);

            //Print the answer of end node
            printf("%d\n",dist[v]);
        }

        //Clear graph and map
        for(int i=0;i<=n;i++)
            cities[i].clear();
        mp.clear();
    }
}
