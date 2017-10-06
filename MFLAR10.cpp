#include<bits/stdc++.h>

using namespace std;

int main() {
    string str,temp;

    //Read input as full line
    getline(cin,str);

    //While there is input
    while(str != "*") {

        //Convert full into stream
        istringstream strm(str);

        //Read from stream and check first letter of each
        bool isTG = true;
        char prev = ' ';
        while(strm >>temp) {
            temp[0] = tolower(temp[0]);
            if(prev == ' ')
                prev = temp[0];
            else if(temp[0] != prev) {
                isTG = false;
            }
        }

        //If it is Tautogram then print Y else N
        if(isTG)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;

        //Get next input
        getline(cin,str);
    }
}
