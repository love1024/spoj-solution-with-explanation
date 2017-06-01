#include<bits/stdc++.h>

using namespace std;

int main() {

    //variable to take each line
    string line;

    //variable to store three number of series
    int a,b,c;

    //loop until there is input
    while(getline(cin,line)) {

        //if there is no more input break from the loop
        if(line == "")
            break;

        //convert the string into numbers
        istringstream cur(line);
        cur>>a>>b>>c;

        //if it is a AP series and also not AP with 0 difference
        if(b-a == c-b && b-a != 0) {
            cout<<"AP "<<(c+(c-b))<<endl;
        } else if(a == 0  || b == 0 ||  c == 0){

            //if any number is zero it can become invalid or
            //GP with ratio 0 so print only empty line
            cout<<endl;
        }else {

            //otherwise it a GP
            cout<<"GP "<<c*(b/a)<<endl;
        }
    }
}
