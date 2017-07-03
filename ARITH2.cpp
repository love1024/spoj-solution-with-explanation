#include<bits/stdc++.h>

using namespace std;

int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Ignore the carriage return
    cin.ignore();

    //line to store entire line
    string line;

    //To store result of calculation
    long long int res = -1;

    //Store the operand other than res
    int b;

    //character to store operator
    char o;

    //Get line from console
    getline(cin,line);
    getline(cin,line);

    //While there is input
    while(line != "") {

        //put string in string stream to get operand and operator
        istringstream strm(line);
        strm>>res;

        //Traverse all line
        while(strm) {

            //Take operator and operand
            strm>>o>>b;

            //Perform calculation according to operator
            if(o == '=')
                break;
            else if(o == '+')
                res = res + b;
            else if(o == '-')
                res = res - b;
            else if(o == '*')
                res = res*b;
            else if(o == '/')
                res = res/b;
        }

        //Print the result
        cout<<res<<endl;

        //Take next line
        getline(cin,line);
        getline(cin,line);
    }
    return 0;
}
