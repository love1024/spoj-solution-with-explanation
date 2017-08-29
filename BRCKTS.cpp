#include<bits/stdc++.h>

using namespace std;

//Node of segment tree
class Node {
public:
    int left,right;
    Node(int left,int right) {
        this->left = left;
        this->right = right;
    }
    Node() {}
};

//Get size of segment tree
int getSize(int n) {
    int sze = 1;
    while(sze < n) {
        sze <<= 1;
    }
    return sze<<1;
}

//Make segment tree
void makeTree(Node seg[],string &str,int p,int i,int j) {
    if(i >= j) {
        if(str[i] == '(')
            seg[p] = Node(1,0);
        else
            seg[p] = Node(0,1);
        return;
    }

    int mid = (i+j)/2;

    //Call left and right subtree
    makeTree(seg,str,2*p+1,i,mid);
    makeTree(seg,str,2*p+2,mid+1,j);

    //Find minimum of bracket left from left and bracket right from right
    //As these will form closed pair
    int mn = min(seg[2*p+1].left,seg[2*p+2].right);

    //Add new node to left and right brackets and subtract those
    //which will form pair
    seg[p] = Node(seg[2*p+1].left + seg[2*p+2].left - mn,seg[2*p+2].right + seg[2*p+1].right - mn);
}

//Update the index or reveres and update its parents
void update(Node seg[],int p,int i,int j,int s,int e) {
    if(i == s && j == e) {
        seg[p].left = seg[p].left?0:1;
        seg[p].right = seg[p].right?0:1;
        return ;
    }

    int mid = (i+j)/2;
    if(e <= mid)
        update(seg,2*p+1,i,mid,s,e);
    else if(s > mid)
        update(seg,2*p+2,mid+1,j,s,e);
    else {
        update(seg,2*p+1,i,mid,s,mid);
        update(seg,2*p+2,mid+1,j,mid+1,j);
    }
    int mn = min(seg[2*p+1].left,seg[2*p+2].right);
    seg[p] = Node(seg[2*p+1].left + seg[2*p+2].left - mn,seg[2*p+2].right + seg[2*p+1].right - mn);
}


int main(){

    //Loop over all test cases
    int t = 10,n,m,q,k=1;
    string str;
    while(t--) {

        //Get number of nodes,string and number of queries
        cin>>n>>str>>m;
        cout<<"Test "<<k<<":"<<endl;

        //Get size of segment tree and make segment tree
        int sze = getSize(n);
        Node seg[sze+1];
        makeTree(seg,str,0,0,n-1);

        //Loop over all queries
        int q;
        for(int i=0;i<m;i++) {

            //Take query and act accordingly
            cin>>q;
            if(q == 0) {
                if(seg[0].left == 0 && seg[0].right == 0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            } else {
                update(seg,0,0,n-1,q-1,q-1);
            }
        }
        k++;
    }
}
