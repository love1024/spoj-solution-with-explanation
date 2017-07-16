#include<bits/stdc++.h>

using namespace std;

//Ref - KMP algorithm

//Function to find longest proper suffix of every character
//of the pattern
void prefixFunction(string &pat,long long arr[])
{
    arr[0] = 0;
    int len = 0;
    for(int i=1; i<pat.length(); i++)
    {
        if(pat[i] == pat[len])
        {
            len++;
            arr[i] = len;
        }
        else
        {
            if(len > 0)
            {
                len = arr[len-1];
                i--;
            }
            else
            {
                arr[i] = 0;
            }
        }
    }
}

int main()
{
    //String for pattern and text
    string pat,temp;

    //Take the first input which is length of pattern
    getline(cin,temp);

    //While there is input
    while(temp != "")
    {

        //Take pattern
        cin>>pat;

        //Find length of pattern
        long long l = pat.length();

        //Array to store longest proper suffix of pattern
        long long lps[l];

        //Find longest proper suffix of array
        prefixFunction(pat,lps);

        //Variable to store next character
        char c;
        cin.ignore();

        //Here k will donate position in pattern
        //And i will donate position in text
        int k = 0,i = 0;

        //To check if we have find any match
        bool flag = true;

        //While there is input stream of text
        while((c = getchar()) != '\n')
        {
            //if this a mismatch with the text
            //Then check how many characters
            //can still be used for matching
            //Using longest prefix suffix array
            while(k != 0 && c != pat[k])
                k = lps[k-1];

            //if this is a match
            if(c == pat[k])
            {
                //Increase the length
                k++;

                //if this is a match with pattern or full length of
                //pattern is covered
                if(k == l)
                {

                    //Print the starting position where pattern is found
                    printf("%d\n",i-k+1);

                    //Take the suffix in found pattern which we can
                    //use for next input
                    k = lps[k-1];

                    //Make false as pattern is found
                    flag = false;
                }
            }

            //Increment position in text
            i++;
        }

        //If no pattern is found print empty line
        if(flag)
            cout<<endl;

        //Take next line characters
        getline(cin,temp);
    }
    return 0;
}
