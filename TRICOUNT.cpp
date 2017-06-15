#include<bits/stdc++.h>

using namespace std;

//REF - http://jwilson.coe.uga.edu/EMAT6680Fa06/Kitchings/cnkEMAT6600/inprogress/Triangle%20Counting/trianglecounting2.html

//The Question is all about formulas
//Try to derive then as cannot be explain
//fully here
int main() {
    int t;
    cin>>t;

    while(t--) {
        long long n;
        cin>>n;

        //First find the number of smallest rectangles which start from top
        //as 1 then 3 at below row then 5 and so on
        //1 + 3 + 5...(sum of odd numbers) = n*n
        //These rectangles take only one row in triangle
        long long t = n*n;

        //Now starting finding all triangles which take 2 rows and then which take
        //3 rows until n-1 which is full rangle
        //Here we will see that it will sum of triangular series
        //Largest triangle (n-1 rows) will form 1 triangle
        //Triangle with n-2 rows will form 3 triangle
        //Triangle with n-3 rows will form 6 triangle
        //So 1 + 3 + 6 + 10 ....
        //which is given by sum of triangular series = n*(n+1)*(n+2)/6
        //here n is n-1
        //These triangles have base below then top
        t += (n*(n+1)*(n-1))/6;

        //These all rectangles which are inverted or have base
        //above than top
        //We can see that we can only form inverted triangles
        //if largest triangle has double the size of triangle
        //we want to find
        //And it will sum of odd or even sum of triangular series
        //according to if given number is even or odds
        int orig = n;
        n = n/2 -1;

        //if number is even
        //Then find sum of first n odd triangular numbers
        if(orig%2 == 0)
            t += (n*(4*n-1)*(n+1))/6;
        else
        //else find sum of first n even triangular numbers
            t += (n*(4*n+5)*(n+1))/6;

        cout<<t<<endl;
    }
    return 0;
}
