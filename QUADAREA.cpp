#include<bits/stdc++.h>

using namespace std;

//ref - https://en.wikipedia.org/wiki/Brahmagupta%27s_formula
// Area is sqrt((s-a)(s-b)(s-c)(s-d))
// where s is (a+b+c+d)/2
int main() {

    //Number of test cases
    int t;
    cin>>t;


    while(t--) {

        //Take sides
        double a,b,c,d,s,res;
        cin>>a>>b>>c>>d;

        //find semi perimeter
        s = (a+b+c+d)*0.5;

        //Find area*area
        res = (s-a)*(s-b)*(s-c)*(s-d);

        //find area
        res = sqrt(res);

        //Print result with precision
        cout<<fixed<<setprecision(2)<<res<<endl;
    }
}
