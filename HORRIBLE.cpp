#include<bits/stdc++.h>

using namespace std;

long long arr[100005];

//Get the size of segment tree it will
//equal to the complete tree greater than n
long long getSize(long long n) {
    long long sze = 1;
    while(sze < n) {
        sze<<=1;
    }
    return sze<<1;
}

//Update the interval using lazy propagation
//In lazy propagation we store the val that is needed
//to update to the children of an interval
//So that we can return back the value we there is query
//for children of this interval
void update(long long seg[],long long lazy[],long long n,long long val,long long p,long long s,long long e,long long i,long long j) {

    //When it is the required interval
    if(s == i && e == j) {

        //Add the sum of all children to current node
        //As we are not going to update children
        seg[p] += (j-i+1)*val;

        //Store the value so that we can know that
        //children are need to update
        lazy[p] += val;
        return;
    }

    //Take the mid value
    long long mid = (i+j)/2;

    //if the interval is completely to the left
    if(e <= mid)
        update(seg,lazy,n,val,p*2+1,s,e,i,mid);

    //else if completely to the right
    else if(s > mid)
        update(seg,lazy,n,val,p*2+2,s,e,mid+1,j);
    else {

        //Else if partial make call to right and left node
        update(seg,lazy,n,val,p*2+1,s,mid,i,mid);
        update(seg,lazy,n,val,p*2+2,mid+1,e,mid+1,j);
    }

    //Now sum at this node is of left child + right child + the sum of children that is pending
    seg[p] = seg[2*p+1] + seg[2*p+2] + lazy[p]*(j-i+1);
}

//Get the sum in interval s to t
//Sum is same as update but here we also
//return the lazy value that is stored by some
//nodes that there children needed to update
//So when we make query for their children
//Node will automatically add it to result
long long getSum(long long seg[],long long lazy[],long long n,long long p,long long s,long long e,long long i,long long j) {

    //If this is the required interval return its value
    if(s == i && e == j) {
        return seg[p] ;
    }

    //Take the mid value
    long long mid = (i+j)/2;

    //if interval is completely left return its value + if this node is storing any children value
    if(e <= mid)
        return getSum(seg,lazy,n,p*2+1,s,e,i,mid) + lazy[p]*(e-s+1) ;

    //if interval is completely right
    else if(s > mid)
        return getSum(seg,lazy,n,p*2+2,s,e,mid+1,j) + lazy[p]*(e-s+1);
    else {

        //If interval is left and right
        long long left = getSum(seg,lazy,n,p*2+1,s,mid,i,mid);
        long long right = getSum(seg,lazy,n,p*2+2,mid+1,e,mid+1,j);

        //Return value of left child + right child + value stored here for children
        //But only return value for required number of children
        return left+right + lazy[p]*(e-s+1);
    }
}


int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take total numbers and commands
        int n,c;
        cin>>n>>c;
        memset(arr,0,sizeof(arr));

        //Make segment tree and initialize it to 0
        long long sze = getSize(n);
        long long seg[sze];
        long long lazy[sze];
        for(long long i=0;i<sze;i++)
            seg[i]=lazy[i]=0;


        //While there are commands
        while(c--) {

            //Take type of query ,interval and value to update if any
            int d,p,q,v;
            cin>>d>>p>>q;

            //If it is update query take value
            if(d == 0)
                cin>>v;

            //If update
            if(d == 0) {
                update(seg,lazy,n,v,0,p-1,q-1,0,n-1);
            } else {

                //Else print the sum of interval
                cout<<getSum(seg,lazy,n,0,p-1,q-1,0,n-1)<<endl;
            }
        }
    }
}
