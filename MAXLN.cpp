#include<bits/stdc++.h>

using namespace std;

//According to Thales theorem triangle form from
//end points of diameter in circle will always be right
//angle triangle so equation will become
// AB*AB + AC*AC = 4*r*r
// Putting AB*AB in the given equation s = AB*AB + AC
// AC + 4*r*r - AC*AC
// Differentiating it and making it equal to 0 to find maximum point
// will give AC equal to 1/2
// We can find AB from first equation and hence answer
int main() {

    //Get number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    for(int i=1;i<=t;i++) {

        //Take the radius
        double r;
        cin>>r;

        //Y should be 0.5 to maximize equation
        double y = 0.5;

        //X can be find using this equation
        double x = (16.0*r*r - 1)/4.0;

        //Print the result
        cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<(x+y)<<endl;
    }
}
