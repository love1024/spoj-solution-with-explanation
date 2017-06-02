#include<bits/stdc++.h>

using namespace std;

int main() {

    //variables to store column and row length
    int c,r;

    //take input of number of column
    cin>>c;

    //loop while column not equal to zero
    while(c != 0) {

        //take string into line
        //NOTE first get line is used to take
        //carriage return which is in buffer
        //after taking input of integer in c
        string line;
        getline(cin,line);
        getline(cin,line);

        //find number of rows from string length
        r = line.length()/c;

        //loop for each column as start
        //of input text
        for(int i=0;i<c;i++) {

            //variable to check whether this row
            //is reversed in input or not
            //as in question alternate row start from
            //different sides
            bool flag = false;
            for(int j=0;j<r;j++) {

                //if this is reversed row then
                //add extra length of column to reach
                //start of this row and subtract the columns
                //which have already visited
                if(flag)
                   cout<<line[j*c+c-i-1];
                else
                    //if row is not reversed just print
                    //the character after skipping characters
                    //which have already visited
                   cout<<line[j*c+i];

                //reverse the check
                flag = !flag;
            }
        }

        //print the new line and take new input
        cout<<endl;
        cin>>c;
    }
}
