#include<bits/stdc++.h>

using namespace std;

#define MAX 2501

//Four list to store input
int a[MAX],b[MAX],c[MAX],d[MAX];

//Vector to store sum of first two and last two lists
vector<int> v1,v2;

int main() {

    //Take number of elements
    int n;
    cin>>n;

    //Take four lists
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    //Store sum of first two lists
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            v1.push_back(a[i]+b[j]);
        }
    }

    //Store sum of last two lists
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            v2.push_back(c[i]+d[j]);
        }
    }

    //Sort the second list for binary search
    sort(v2.begin(),v2.end());

    //Traverse over all sum of first two lists
    long long cnt = 0;
    pair< vector<int>::iterator, vector<int>::iterator > bound;
    for(int i=0;i<v1.size();i++) {

        //Find the range of negative sum in list 2 then add its length to count
        bound = equal_range(v2.begin(),v2.end(),-1*v1[i]);
        cnt += ((bound.second) - (bound.first));
    }

    //Print the answer
    cout<<cnt<<endl;
}
