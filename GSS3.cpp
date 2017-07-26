#include<bits/stdc++.h>

using namespace std;

//Return the size of segment tree
//Which will be complete tree greater than n
int getSize(int n) {
    int sze = 1;
    while(sze <= n) {
        sze <<= 1;
    }
    return sze<<1;
}

//Node to store in segment tree
class Node {
public:

    //Prefix max sum,suffix max sum, totalSum and maximum sum
    int prefixSum;
    int suffixSum;
    int totalSum;
    int maxSum;

    Node() {}

    Node(int val) {
        prefixSum = suffixSum  = totalSum  = maxSum = val;
    }

    //Merge two by finding the maximum sum we can get
    void mergeNodes(Node &left,Node &right) {

        //Total sum of this node
        totalSum = left.totalSum + right.totalSum;

        //Maximum prefix and suffix sum we can form
        prefixSum = max(left.prefixSum,left.totalSum + right.prefixSum);
        suffixSum = max(right.suffixSum,left.suffixSum + right.totalSum);

        //Maximum sum we can get
        maxSum = max(left.maxSum,max(right.maxSum,left.suffixSum+right.prefixSum));
    }
};

//Build the segment tree
Node build(int arr[],Node seg[],int p,int i,int j) {

    //if this is leaf node
    if(i == j) {

        //Store the value in node and return it
        seg[p] = Node(arr[i]);
        return seg[p];
    }

    //Get mid value and traverse left and right
    int mid = (i+j)/2;
    Node left = build(arr,seg,2*p+1,i,mid);
    Node right = build(arr,seg,2*p+2,mid+1,j);

    //Store the result of left and right node in this node
    seg[p].mergeNodes(left,right);

    //Return current node
    return seg[p];
}


//Update the value of index donated by s or e
//S and e are same here just for compliance with query function
void update(Node seg[],int val,int p,int s,int e,int i,int j) {

    //If this is the required index update its value
    if(i == s && j == e) {
        seg[p] = Node(val);
        return ;
    }

    //Find the mid and traverse according to where
    //Query lies
    int mid = (i+j)/2;
    if(e <= mid)
        update(seg,val,2*p+1,s,e,i,mid);
    else if(s > mid)
        update(seg,val,2*p+2,s,e,mid+1,j);
    else {
        update(seg,val,2*p+1,s,mid,i,mid);
        update(seg,val,2*p+2,mid+1,e,mid+1,j);
    }

    //After updating children update current node
    seg[p].mergeNodes(seg[2*p+1],seg[2*p+2]);
}

//Query the segment tree
Node query(Node seg[],int p,int s,int e,int i,int j) {

    //If this is the required range return its value
    if(i == s && j == e) {
        return seg[p];
    }

    //Find mid and traverse according to query lies
    int mid = (i+j)/2;
    if(e <= mid)
        return query(seg,2*p+1,s,e,i,mid);
    else if(s > mid)
        return query(seg,2*p+2,s,e,mid+1,j);
    else {

        //Here we have result from left and right
        //Find the max in this range and return it
        Node left = query(seg,2*p+1,s,mid,i,mid);
        Node right = query(seg,2*p+2,mid+1,e,mid+1,j);
        Node res;
        res.mergeNodes(left,right);
        return res;
    }
}

int main() {

    //Number of elements and queries
    int n,m;
    cin>>n;

    //Take value in array
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Take array for segment tree
    int sze = getSize(n);
    Node seg[sze+1];

    //Initialize segment tree
    for(int i=0;i<sze;i++)
        seg[i] = Node(0);

    //Build segment tree according to the question
    build(arr,seg,0,0,n-1);

    //Take number of queries
    cin>>m;

    //t is type of query
    int t,x,y;

    //Loop over all queries
    while(m--) {

        //Take query and perform according to t
        cin>>t>>x>>y;
        if(t == 0) {
            update(seg,y,0,x-1,x-1,0,n-1);
        } else {
            cout<<query(seg,0,x-1,y-1,0,n-1).maxSum<<endl;;
        }
    }
    return 0;
}
