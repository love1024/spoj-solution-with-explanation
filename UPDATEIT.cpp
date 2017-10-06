#include<bits/stdc++.h>

using namespace std;

//Get size of segment tree
int getSize(int n) {
    int sze = 1;
    while(sze < n) {
        sze <<= 1;
    }
    return sze<<1;
}

//Update tree with lazy propagation to store the result that
//should be returned will querying
void update(int lazy[],int l,int r,int s,int e,int p,int val) {
    if(l == s && e == r) {
        lazy[p] += val;
        return;
    }
    int mid = (s+e)/2;
    if(r <= mid)
        update(lazy,l,r,s,mid,2*p+1,val);
    else if(l > mid)
        update(lazy,l,r,mid+1,e,2*p+2,val);
    else {
        update(lazy,l,mid,s,mid,2*p+1,val);
        update(lazy,mid+1,r,mid+1,e,2*p+2,val);
    }
}

//Query the array and return result from lazy array
//As they are used to update array
int query(int lazy[],int idx,int s,int e,int p) {
    if(s == idx && e == idx)
        return lazy[p];
    int mid = (s+e)/2;
    if(idx <= mid)
        return query(lazy,idx,s,mid,2*p+1) + lazy[p];
    else if(idx > mid)
        return query(lazy,idx,mid+1,e,2*p+2) + lazy[p];
    else {
        return (query(lazy,idx,s,mid,p) +
                query(lazy,idx,mid+1,e,p) +
                lazy[p]);
    }
}

int main() {

    //Take test cases
    int t,n,u,l,r,val,q,idx;
    scanf("%d",&t);

    //While there is input
    while(t--) {

        //Take n and u
        scanf("%d%d",&n,&u);

        //Declare segment tree lazy array
        int sze = getSize(n);
        int lazy[sze];
        memset(lazy,0,sizeof(lazy));

        //Take input and update segment tree lazy array
        //accordingly
        for(int i=0;i<u;i++) {
            scanf("%d%d%d",&l,&r,&val);
            update(lazy,l,r,0,n-1,0,val);
        }

        //Take queries and give answer with query to segment tree
        scanf("%d",&q);
        for(int i=0;i<q;i++) {
            scanf("%d",&idx);
            printf("%d\n",query(lazy,idx,0,n-1,0));
        }
    }
}
