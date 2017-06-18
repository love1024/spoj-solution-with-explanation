#include<bits/stdc++.h>

using namespace std;

//Const for pie and 0 value in double
const double PIE = 3.14159;
const double zero = 0;

int main() {

    //Take the length of fence
    double l;
    cin>>l;

    //While fence length is not equal to zero
    while(l != zero) {

        //Find area of by using semi circle that the
        //fence will form with the wall for maximum area
        double area = l*l/(2.0*PIE);

        //Fixed the precision and print area
        cout<<fixed<<setprecision(2)<<area<<endl;

        //take next value
        cin>>l;
    }
}

