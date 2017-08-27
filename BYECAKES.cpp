#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take input
    int E,F,S,M,E1,F1,S1,M1;
    cin>>E>>F>>S>>M>>E1>>F1>>S1>>M1;

    //Loop while there are test cases
    while(F != -1) {

        //Find the upper limit of cakes we can make
        //in every case. for example in 4 2 we can make 4/2 = 2 cakes
        //Also in 3/2 we have to make 2 cakes
        int E2,F2,S2,M2;
        E2 = ceil((double)E/E1);
        F2 = ceil((double)F/F1);
        S2 = ceil((double)S/S1);
        M2 = ceil((double)M/M1);

        //Find max of these cakes
        int mx = max(max(E2,F2),max(S2,M2));

        //We have make everyone make max cakes
        //If the ingredient are not in multiple of required
        //We add the extra ingredient
        //E2*E1 gives the upper limit on minimum ingredient required
        //We subtract it from our input to find the difference
        cout<<((mx-E2)*E1 + ((E%E1==0)?0:(E2*E1-E)))<<" ";
        cout<<((mx-F2)*F1 + ((F%F1==0)?0:(F2*F1-F)))<<" ";
        cout<<((mx-S2)*S1 + ((S%S1==0)?0:(S2*S1-S)))<<" ";
        cout<<((mx-M2)*M1 + ((M%M1==0)?0:(M2*M1-M)))<<endl;

        cin>>E>>F>>S>>M>>E1>>F1>>S1>>M1;
    }
}
