#include<bits/stdc++.h>

using namespace std;

//Max numbers
#define MAX 500005

//Pre calculate the sequence
int arr[MAX];

//To find duplicate results
set<int> st;

void findSeq() {

    //First number is zero
    arr[0] = 0;

    //Find all numbers
    for(int i=1;i<=MAX;i++) {

        //If subtracting leads to positive number and is not already in sequence
        if(arr[i-1] - i > 0 && st.find(arr[i-1]-i) == st.end()){
            arr[i] = arr[i-1] - i;
            st.insert(arr[i-1]-i);
        }
        else {

            //Else add by adding current i
            arr[i] = arr[i-1] + i;
            st.insert(arr[i-1]+i);
        }
    }
}

int main() {

    //Find sequence
    findSeq();

    //Take number
    int n;
    cin>>n;

    //Print the result
    while(n != -1) {
        cout<<arr[n]<<endl;
        cin>>n;
    }
}
