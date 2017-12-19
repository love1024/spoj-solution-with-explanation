#include<bits/stdc++.h>

using namespace std;

//Get size of segment tree
int getSize(int n) {
    int sze = 1;
    while(sze <= n) {
        sze <<= 1;
    }
    return sze<<1;
}

//Update segment tree using lazy propagation
void update(int seg[],int lazy[],int i,int j,int s,int e,int p) {

    //If this is the required interval
    if(i == s && j == e) {

        //invert the state of bulbs and lazy array
        seg[p] = (e-s+1) - seg[p];
        lazy[p] = lazy[p]?0:1;
        return;
    }
    int mid = (i+j)/2;
    if(e <= mid)
        update(seg,lazy,i,mid,s,e,2*p+1);
    else if(s > mid)
        update(seg,lazy,mid+1,j,s,e,2*p+2);
    else {
        update(seg,lazy,i,mid,s,mid,2*p+1);
        update(seg,lazy,mid+1,j,mid+1,e,2*p+2);
    }

    //If the lazy state is on then try to invert all bulbs by subtracting from total
    seg[p] = lazy[p]*(j-i+1) - (seg[2*p+1] + seg[2*p+2])*(lazy[p]?1:-1) ;
}

int getOn(int seg[],int lazy[],int i,int j,int s,int e,int p) {

    //If this is required interval return it
    if(i == s && j == e) {
        return seg[p];
    }

    //Return the required interval if lazy state is on then invert before returning
    int mid = (i+j)/2;
    if(e <= mid)
        return lazy[p]*(e-s+1) - (getOn(seg,lazy,i,mid,s,e,2*p+1))*(lazy[p]?1:-1);
    else if(s > mid)
        return lazy[p]*(e-s+1) - (getOn(seg,lazy,mid+1,j,s,e,2*p+2))*(lazy[p]?1:-1);
    else {
        int left = getOn(seg,lazy,i,mid,s,mid,2*p+1);
        int right = getOn(seg,lazy,mid+1,j,mid+1,e,2*p+2);
        return lazy[p]*(e-s+1) - (left+right)*(lazy[p]?1:-1);
    }
}

int main() {

    //Take input and print answer
    int n,m,q,a,b;
    scanf("%d%d",&n,&m);

    int sze = getSize(n);
    int seg[sze],lazy[sze];
    memset(seg,0,sizeof(seg));
    memset(lazy,0,sizeof(lazy));


    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&q,&a,&b);
        if(q == 0) {
            update(seg,lazy,0,n-1,a-1,b-1,0);
        } else {
            printf("%d\n",getOn(seg,lazy,0,n-1,a-1,b-1,0));
        }
    }

}
