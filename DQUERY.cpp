#include<bits/stdc++.h>

using namespace std;

//ref - http://www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/

//The block size which will be sqrt(n)
int blockSize ;

//Max size of integer allowed
const int MAX = 1000005;

//Temporary array to store number of numbers
int temp[MAX];

//Structure to store each query
class Query {
public:
    int left;
    int right;
    int pos;
    int ans;
    Query(int left,int right,int pos) {
        this->left = left;
        this->right = right;
        this-> pos = pos;
    }
};

//Compare queries according to MO order
bool compare(Query &a,Query &b) {
    if(a.left/blockSize == b.left/blockSize)
        return a.right < b.right;
    else
        return a.left/blockSize < b.left/blockSize;
}

//Compare queries according to their position
bool compareByPos(Query &a,Query &b) {
    return a.pos < b.pos;
}

//The idea is to use MO order to sort queries
//Then go from one query to another
//It can be done using MO order in n*sqrt(n)
int main() {

    //Take number of numbers
    int n;
    scanf("%d",&n);

    //Take numbers
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);;

    //Take number of queries
    int q,l,r;
    scanf("%d",&q);

    //Take queries in vector
    vector<Query> vec;
    for(int i=0;i<q;i++) {
        scanf("%d%d",&l,&r);
        vec.push_back(Query(l,r,i));
    }

    //Find the block size
    blockSize = sqrt(n);

    //Sort the queries according to MO order
    sort(vec.begin(),vec.end(),compare);

    //Loop over all queries
    //Here left and right will donate the array currently
    //covered from queries
    int left=1,right=0,cnt=0;
    for(int i=0;i<q;i++) {

        //Take the current query
        Query cur = vec[i];

        //Find the current query left and right
        int curL = cur.left;
        int curR = cur.right;

        //If right is less than the current right
        //Then increase right and add if there is new
        //distinct element
        while(right < curR) {
            right++;
            if(temp[arr[right-1]] == 0)
                cnt++;
            temp[arr[right-1]]++;
        }

        //If right is greater than current right
        //Then decrease the right and if on the
        //way any number becomes zero decrease count
        //As the number is completely gone out of range
        while(right > curR) {
            temp[arr[right-1]]--;
            if(temp[arr[right-1]] == 0)
                cnt--;
            right--;
        }

        //If the left is less than the current left
        //Then increase left or decrease size of range
        //So we decrease count whenever any element
        //becomes zero number of times
        while(left < curL) {
            temp[arr[left-1]]--;
            if(temp[arr[left-1]] == 0)
                cnt--;
            left++;
        }

        //When left is greater than current left then
        //Decrease left and add new distinct elements if any
        while(left > curL) {
            left--;
            if(temp[arr[left-1]] == 0)
                cnt++;
            temp[arr[left-1]]++;
        }

        //Add current count as answer of this query
        vec[i].ans = cnt;
    }

    //Sort the queries according to position
    sort(vec.begin(),vec.end(),compareByPos);

    //Print the answers
    for(int i=0;i<vec.size();i++)
        printf("%d\n",vec[i].ans);
}
