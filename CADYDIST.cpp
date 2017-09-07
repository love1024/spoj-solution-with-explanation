#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take total number
    int N;
    cin>>N;

    //While there is input
    while(N != 0) {

        //Take students and cost of candies
        vector<long long> C(N), P(N);

        for(int i=0;i<N;i++)
            cin>>C[i];

        for(int i=0;i<N;i++)
            cin>>P[i];

        //Sort input
        long long int cost = 0;
        sort(C.begin(),C.end());
        sort(P.begin(),P.end());

        //Sort students from max and candies cost from min
        //So that we can have minimum multiplication possible
        for(int i=0;i<N;i++) {
            cost += (C[N-i-1]*P[i]);
        }

        //Print the answer
        cout<<cost<<endl;
        cin>>N;
    }
}
