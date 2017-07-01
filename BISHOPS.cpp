#include<bits/stdc++.h>

using namespace std;

//Function to convert integer into string
string getStr(int x)
{
    ostringstream strm;
    strm<<x;
    return strm.str();
}

//Function to add two string
//and return new string
string add(string &a,string &b)
{
    string res = "";
    int c = 0;
    int i = a.length()-1,j = b.length()-1;
    while(i >= 0 || j >= 0)
    {
        int cur = 0;
        if(i >= 0)
            cur = cur +  (a[i]-'0');
        if(j >= 0)
            cur = cur +  (b[j]-'0');
        cur = cur + c;
        res = getStr(cur%10) + res;
        c = cur/10;
        i--,j--;
    }
    if(c > 0)
        res = getStr(c)+res;
    return res;
}

//Function to subtract two string
//and return a new string
string subtract(string &f,string &s)
{
    string res = "";
    int c = 0;
    int i = f.length()-1,j = s.length()-1;
    while(i >= 0 || j >= 0)
    {
        int a = i>=0?(f[i]-'0'):0;
        int b = j>=0?(s[j]-'0'):0;
        if(a >= b+c)
        {
            res = getStr(a-b-c) + res;
            c = 0;
        }
        else
        {
            res = getStr(10+a-b-c) + res;
            c = 1;
        }
        i--,j--;
    }
    return res;
}

int main() {

    //Variable to store number
    string num,subtractTwo = "2";

    //Get the number
    getline(cin,num);

    //Loop while there is no number
    while(num != "") {

        //if it 1X1 then we can place only one bishop
        if(num == "1")
            cout<<"1"<<endl;
        else {

            //else the number of bishops we can place are
            //We can fill first full line
            //and also the last line expect the corner ones
            //This will give maximum bishops we can place
            //For corner cases we have subtracted two
            string temp = subtract(num,subtractTwo);

            //Print the result
            cout<<add(num,temp)<<endl;
        }

        //Take next input
        getline(cin,num);
    }
}
