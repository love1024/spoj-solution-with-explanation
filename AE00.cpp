#include<bits/stdc++.h>

using namespace std;

//To find number of rectangle we can form
//with n given squares is equal to
//finding the factors that will multiply
//equal to n
//e.g for 6
//1X6 and 2X3
int main() {

    //take number of squares
    int n;
    cin>>n;

    //count total number of rectangles
    int cnt = 0;

    //go for all number of squares
    for(int i=1;i<=n;i++) {

        //for each number of squares find number
        //of unique factor
        for(int j=1;j<=sqrt(i);j++) {
            if(i%j == 0)
                cnt++;
        }
    }

    //print total number of rectangles.
    cout<<cnt<<endl;
}
