#include<bits/stdc++.h>

using namespace std;

//Node to store in segment tree
//Each Node will store 2 maximum elements
class Node{
public:
    int mx1,mx2;
    Node(int mx1,int mx2) {
        this->mx1 = mx1;
        this->mx2 = mx2;
    }
    Node() {}
};

//Get size of segment tree
long getSize(long n) {
    long sze = 1;
    while(sze < n) {
        sze <<= 1;
    }
    return sze<<1;
}

//Make segment tree
void makeTree(Node seg[],int arr[],int p,int i,int j) {
    if(i >= j) {
        seg[p] = Node(arr[i],0);
        return ;
    }
    int mid = (i+j)/2;
    makeTree(seg,arr,p*2+1,i,mid);
    makeTree(seg,arr,p*2+2,mid+1,j);

    //First maximum element will be maximum of two maximum elements
    seg[p].mx1 = max(seg[2*p+1].mx1,seg[2*p+2].mx1);

    //Next max element will be
    //if max from both nodes are equal then second maximum will be equal to first
    //Else exclude first maximum and check the max of other node and max2 of same node
    if(seg[2*p+1].mx1 == seg[2*p+2].mx1)
        seg[p].mx2 = seg[p].mx1;
    else
        seg[p].mx2 = (seg[2*p+1].mx1 > seg[2*p+2].mx1)?max(seg[2*p+1].mx2,seg[2*p+2].mx1):max(seg[2*p+2].mx2,seg[2*p+1].mx1);
}

//Query for the range
Node query(Node seg[],int p,int i,int j,int s,int e) {
    if(s == i && e == j) {
        return seg[p];
    }
    int mid = (i+j)/2;
    if(e <= mid)
        return query(seg,p*2+1,i,mid,s,e);
    else if(s > mid)
        return query(seg,p*2+2,mid+1,j,s,e);
    else {
        Node a = query(seg,p*2+1,i,mid,s,mid);
        Node b = query(seg,p*2+2,mid+1,j,mid+1,e);
        Node res;
        res.mx1 = max(a.mx1,b.mx1);
        if(a.mx1 == b.mx1)
            res.mx2 = res.mx1;
        else
            res.mx2 = (a.mx1 > b.mx1)?max(a.mx2,b.mx1):max(b.mx2,a.mx1);
        return res;
    }

}

//Update a single element
void update(Node seg[],int arr[],int p,int i,int j,int s,int e,int val) {
    if(s == i && e == j) {
        seg[p].mx1 = val;
        return ;
    }
    int mid = (i+j)/2;
    if(e <= mid)
        update(seg,arr,p*2+1,i,mid,s,e,val);
    else if(s > mid)
        update(seg,arr,p*2+2,mid+1,j,s,e,val);
    else {
        update(seg,arr,p*2+1,i,mid,s,mid,val);
        update(seg,arr,p*2+2,mid+1,j,mid+1,e,val);
    }

    //After children update the current node
    seg[p].mx1 = max(seg[2*p+1].mx1,seg[2*p+2].mx1);
    if(seg[2*p+1].mx1 == seg[2*p+2].mx1)
        seg[p].mx2 = seg[p].mx1;
    else
        seg[p].mx2 = (seg[2*p+1].mx1 > seg[2*p+2].mx1)?max(seg[2*p+1].mx2,seg[2*p+2].mx1):max(seg[2*p+2].mx2,seg[2*p+1].mx1);

}

int main() {

    //Get number of elements
    int N;
    cin>>N;

    //Take elements
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];

    //Get the size of segment tree
    //make tree and initialize it
    int sze = getSize(N);
    Node seg[sze];
    memset(seg,NULL,sizeof(seg));
    makeTree(seg,arr,0,0,N-1);

    //Get number of queries
    char q;
    int Q,x,y;
    cin>>Q;

    //Loop over all queries and do accordingly
    for(int i=0;i<Q;i++) {
        cin>>q>>x>>y;
        if(q == 'Q') {
            Node res = query(seg,0,0,N-1,x-1,y-1);
            cout<<(res.mx1+res.mx2)<<endl;
        } else {
            update(seg,arr,0,0,N-1,x-1,x-1,y);
        }
    }
}
