#include<bits/stdc++.h>

using namespace std;

int main() {

    //Number of test cases
    int tc;
    cin>>tc;

    //Loop over all test cases
    while(tc--) {

        //Take
        //t - third term, tl - third last
        //s - sum of series, n = number of terms
        //a - first term, d = difference of series
        long long int t,tl,s,n,a,d;

        //Take third, third last and sum of series
        cin>>t>>tl>>s;

        //Find number of terms by sum = numberOfTerms*(first+last)/2;
        //Here first is t-2*d and last is tl+2*d
        //2*d and -2d will get canceled
        n = 2*s/(t+tl);

        //Difference is given by subtraction of
        //t = a + 2*d and tl = a + (n-3)*d;
        d = (tl - t)/(n-5);

        //First term is found from third term
        //t = a + 2*d;
        a = t - 2*d;

        //Now just print the series by adding d at every step
        cout<<n<<endl;
        for(long long i=0;i<n;i++) {
            cout<<(a+d*i)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
