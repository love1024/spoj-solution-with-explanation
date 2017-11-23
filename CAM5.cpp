#include<bits/stdc++.h>

using namespace std;

//Node to store size and parent of each group
class Node {
public:
    int val,sze;
    Node(int val,int sze) {
        this->val = val;
        this->sze = sze;
    }
    Node() {}
};

//Find parent of each group
int parent(Node arr[],int a) {
    if(arr[a].val == a)
        return a;
    return parent(arr,arr[a].val);
}

//Join two groups using union by rank
void join(Node arr[],int a,int b) {
    int p1 = parent(arr,a);
    int p2 = parent(arr,b);
    if(p1 == p2)
        return;
    else if(arr[p1].sze < arr[p2].sze) {
        arr[p1].val = arr[p2].val;
        arr[p2].sze += arr[p1].sze;
    } else {
        arr[p2].val = arr[p1].val;
        arr[p1].sze += arr[p2].sze;
    }
}


int main() {

    //Loop over all test cases
    int t,n,e,a,b;
    cin>>t;

    while(t--) {

        //Take inputs
        cin>>n>>e;

        //At each node store its own value
        Node arr[n];
        for(int i=0;i<n;i++)
            arr[i] = Node(i,1);

        //Now join all groups
        for(int i=0;i<e;i++) {
            cin>>a>>b;
            join(arr,a,b);
        }

        //Print all joined groups count
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(arr[i].val == i)
                cnt++;
        }
        cout<<cnt<<endl;
    }
}
