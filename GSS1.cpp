#include<bits/stdc++.h>

using namespace std;

//Get the size of segment tree needed
int getSize(int n) {
    int sze = 1;
    for(;sze<n; sze <<= 1);
    return sze<<1;
}

//Segment tree Node
class Node {
public:
    //maxSum - Store maximum sum in the range donated by range of current node
    //sum - sum of all range donated by current node
    //prefixMaxSum - max prefix sum
    //suffixSum - max suffix sum
    int prefixMaxSum,suffixMaxSum,maxSum,sum;

    Node() {}

    Node(int val){
        prefixMaxSum = suffixMaxSum = maxSum = sum = val;
    }

    //Assign different values to this node from left and right node
    void mergeNode(Node &left,Node &right) {

        //Sum of left and right node
        sum = left.sum + right.sum;

        //max prefix can be of left prefix sum or sum of left + prefix of left
        prefixMaxSum = max(left.prefixMaxSum,left.sum+right.prefixMaxSum);

        //max suffix can be of right suffix or sum of right + suffix of left
        suffixMaxSum = max(right.suffixMaxSum,left.suffixMaxSum+right.sum);

        //Maximum sum can of in left or in right or suffix of left and prefix of right
        maxSum = max(right.maxSum,max(left.maxSum,left.suffixMaxSum+right.prefixMaxSum));
    }
};

//Build the segment tree
Node preprocess(int arr[],Node st[],int l,int r,int idx) {

    //If it is a leaf the assign value of element to node
    if(l == r) {
        st[idx] = Node(arr[l]);
        return st[idx];
    }

    //Find the mid
    int mid = (l+r)/2;

    //Build left half of segment tree
    Node left = preprocess(arr,st,l,mid,2*idx+1);

    //Build right half of segment tree
    Node right = preprocess(arr,st,mid+1,r,2*idx+2);

    //Now merge left and right half in this current node
    st[idx].mergeNode(left,right);

    //Return current node
    return st[idx];
}

Node getMax(Node st[],int s,int e,int l,int r,int idx) {

    //If given range is equal to current left and right return current node
    if(s == l && e == r)
        return st[idx];

    //Find the mid
    int mid=(l+r)/2;

    //If given range is completely left of mid the traverse only left
    if(e <= mid)
        return getMax(st,s,e,l,mid,2*idx+1);
    else if(s > mid)

        //else if given range is completely right of mid then traverse right only
        return getMax(st,s,e,mid+1,r,2*idx+2);
    else {

        //Else range is partially in left and right
        Node left,right,res;

        //Find max in left half
        left= getMax(st,s,mid,l,mid,2*idx+1);

        //Find max in right half
        right = getMax(st,mid+1,e,mid+1,r,2*idx+2);

        //Find maximum of current range by merging of left and right
        res.mergeNode(left,right);

        //return maximum node
        return res;
    }
}

int main() {

    //Number of nodes and queries
    int n,m;

    //Get number of nodes
    scanf("%d",&n);

    //Take values in array
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    //Build segment tree
    Node st[getSize(n)];
    preprocess(arr,st,0,n-1,0);

    //Take queries
    scanf("%d",&m);
    int s,e;

    //Loop over all queries
    for(int i=0;i<m;i++) {

        //Take range of query
        scanf("%d %d",&s,&e);

        //Find the maximum subsegment sum
        printf("%d\n",getMax(st,s-1,e-1,0,n-1,0).maxSum);
    }
    return 0;
}
