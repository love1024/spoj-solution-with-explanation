#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take Number of Attacking and defencing player
    int A,D,x;
    cin>>A>>D;

    //While there is input
    while(A != 0 && D != 0) {

        //Take
        //minA = minimum of Attacking players
        //minD1,minD2 - minimum two of Defencing players
        int minA,minD1,minD2;
        minA = minD1 = minD2 = INT_MAX;

        //Find minimum of Attacking player
        for(int i=0;i<A;i++) {
            cin>>x;
            minA = min(minA,x);
        }

        //Find two minimum of Defence player
        for(int i=0;i<D;i++) {
            cin>>x;
            if(x <= minD1) {
                minD2 = minD1;
                minD1 = x;
            } else if(x < minD2)
                minD2 = x;
        }

        //If Attacking player is behind second last
        //Defencing player then there is offside else no
        if(minA < minD2 )
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;

        //Take next input
        cin>>A>>D;
    }
    return 0;
}
