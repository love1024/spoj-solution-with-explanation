#include<bits/stdc++.h>

using namespace std;

//Function to check whether string is number or not
bool isNumber(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        int cur = str[i] - '0';
        if(cur < 0 || cur > 9)
            return false;
    }
    return true;
}

//Function to convert integer into string
string getStr(int x)
{
    ostringstream strm;
    strm<<x;
    return strm.str();
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

//Function to trim zero at start of string
string trim(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] != '0')
            return str.substr(i,str.length());
    }
    return str;
}

int main()
{
    //Take number of test cases
    int t;
    cin>>t;

    //To store each string
    string str;
    cin.ignore();

    //Loop over all test cases
    while(t--)
    {
        //Ignore empty line and take next line
        cin.ignore();
        getline(cin,str);

        //To store number and operators
        string a,b,c,o1,o2;
        istringstream line(str);
        line>>a>>o1>>b>>o2>>c;

        //Check which one is not number and find it and print answer
        //Also trim string before printing
        if(!isNumber(c))
            cout<<a<<" + "<<b<<" = "<<trim(add(a,b))<<endl;
        else if(!isNumber(a))
            cout<<trim(subtract(c,b))<<" + "<<b<<" = "<<c<<endl;
        else
            cout<<a<<" + "<<trim(subtract(c,a))<<" = "<<c<<endl;
    }
}
