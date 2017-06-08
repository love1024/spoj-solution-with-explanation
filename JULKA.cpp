#include<bits/stdc++.h>

using namespace std;

//Function to convert integer into string
string getStr(int x)
{
    ostringstream strm;
    strm<<x;
    return strm.str();
}

//Function to divide string by a number x
//and return a new string
string divide(string &str,int x)
{
    string res = "";
    int c = 0;
    for(int i=0; i<str.length(); i++)
    {
        int cur = str[i] - '0';
        cur = c*10 + cur;
        res += getStr(cur/x);
        c = cur%x;
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

void print(string &str)
{
    //loop to print apple klaudia have
    //flag to skip any zeroes at start
    //last condition is used if there is
    //zero in input
    bool flag = true;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '0' && flag && i != str.length()-1)
            continue;
        else
        {
            cout<<str[i];
            flag = false;
        }
    }
    cout<<endl;
}

int main()
{
    //Hold the current apples and difference
    string str ;
    string diff;
    string k,n;

    //while there is input
    while(getline(cin,str))
    {
        //if there is no input break
        if(str == "")
            break;

        //take the difference
        cin>>diff;

        //Divide the string into half
        //so that both can have equal apples
        //if string is even or natalia can have
        //one more apple if string is odd
        //here k donate apples klaudia have
        k = divide(str,2);

        //temp string which is used to increment
        //difference by 1 if string number is odd
        //and klaudia has one less apple when
        //we are dividing apples into half
        string temp = "1";
        if((str[str.length()-1]-'0')%2!=0)
            diff = add(diff,temp);

        //dividing difference by half
        //increase klaudia apple by this half
        //and decrease natalia apple by half
        diff = divide(diff,2);

        //increasing klaudia apples by half
        k = add(k,diff);

        //natalia apples can be find by subtracting
        //klaudia apples from all apples
        n = subtract(str,k);

        //print both results
        print(k);
        print(n);

        //getting extra carriage at end of line
        getline(cin,str);
    }
}
