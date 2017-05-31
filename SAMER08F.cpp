#include<bits/stdc++.h>

using namespace std;

//ref - http://mathforum.org/library/drmath/view/56167.html

//WORKING
/*
    The main formula is
    n*n + (n-1)*(n-1) + ... 1*1 = n*(n+1)*(2n+1)/2
    consider example of n = 3;
    1X1 sqaure:
        for each fixed position vertically of 1 length(as square is of 1 length)
        we have 3 choices horizontally.
        and we have 3 choices vertically so total is of 3*3 = 9
    2X2 square:
        for each fixed position vertically of length 2
        we have 2 choices horizontally.
        and we have 2 choices vertically so total is of 2*2 = 4;
    3X3 square:
        we have 1 choice horizontally and vertically
        so total is of 1*1 = 1 choice
    so total we have = 9+4+1 = 14 choices
*/

int main() {

    //string to store number as
    //we need string to check for
    //end of input
    string line;

    //integer to store number
    int n;

    //every time take new line
    while(getline(cin,line)) {

        //if line is empty
        if(line == "")
            break;

        //convert to integer from string
        //and store it in n
        istringstream cur(line);
        cur>>n;

        //if number is zero then print a empty line
        if(n == 0)
            cout<<endl;

        //else print using formula
        else
            cout<<((n*(n+1)*(2*n+1))/6)<<endl;
    }
}
