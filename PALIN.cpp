#include<bits/stdc++.h>

using namespace std;
/*
    The logic of solution is divided into two parts
    FIRST
        We start from mid and check if we can
        find any number on the left which is greater
        than any number on the right at similar position(as in palindrome)
        then we know that number at the right can cover
        all increases to its right
        e.g 543212 now here we first compare 3 and 2
        as 3 is greater than 2 . now 2 can increase and can
        also cover all increases to its right so that number
        can become 543345. If we can find such number before
        we find any right number greater than left number
        than we are done else go for part SECOND
    SECOND
        Here we know that numbers at the left of mid will
        also increase we haven't found any greater number
        on the right side.So we start from mid add carry to
        every number starting from 1 and make right number
        similar to it equal to this new number after adding carry.
        At last if we left with carry add it to start and make
        this string palindrome by just making left and right number
        equal
        We start from carry one as we have to find next palindrome
        so we add one at start

*/

//Function to convert integer into string
string getStr(int x)
{
    ostringstream strm;
    strm<<x;
    return strm.str();
}

//Make palindrom funtion of SECOND case
void makePalindrome(string &str) {

    //take the mid value
    int mid = str.length()/2;

    //make both i and j equal to mid
    int i=mid,j = mid;

    //if it is even length string decrease i by 1
    i = i + ((str.length()&1)?0:-1);

    //make carry equal to one
    int c = 1;

    //while there are numbers on left
    while(i >= 0) {

        //take the current number
        int cur = str[i]-'0';

        //add carry to it and store it
        str[i] = ((cur+c)%10) + '0';

        //take current carry
        c = (cur+c)/10;

        //make number on right equal to this number
        str[j] = str[i];
        i--,j++;
    }

    //if there is carry left and it to start
    if(c > 0)
        str = getStr(c) + str;

    //as we may have added carry make it palindrome again
    //by just making number at right equal to left
    for(i=0,j=str.length()-1;i<=j;i++,j--)
        str[j] = str[i];
}

//Function to check FIRST case
bool check(string &str) {

    //take flag which donate whether we have
    //found a larger number of not
    bool flag = false;

    //take mid of string
    int mid = str.length()/2;

    //make and i and j equal to mid
    int i=mid,j = mid;

    //decrease i if string is of even length
    i = i + ((str.length()&1)?0:-1);

    //loop until there are characters on left
    while(i >= 0) {

        //if the current left character is greater than
        //right than we have found the larger number
        //so make flag equal to true
        if(str[i] > str[j]) {
            str[j] = str[i];
            flag = true;
        }
        //else if current character are equal or
        //in case left is smaller than right but
        //we have already found a greater number before
        //so we can make them equal as grater number we
        //cover for this.
        else if(str[i] == str[j] || flag)
            str[j] = str[i];
        //else if haven't found the greater number
        //and number of left is lesser than number
        //on right then break and go for case SECOND
        else
            break;
        i--,j++;
    }

    //return flag
    return flag;
}

int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Store number in string
    string str;
    while(t--) {

        //take string input
        cin>>str;

        //if FIRST case failed then go for second
        if(!check(str))
            makePalindrome(str);

        //print the string
        cout<<str<<endl;
    }
}
