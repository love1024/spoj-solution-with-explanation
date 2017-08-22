#include<bits/stdc++.h>

using namespace std;

//Max length of the string
const int MAXN = 1024;

//Max power of 2 that is greater than MAXN
const int MAXP = 12;

//Levels to store the string whose characters at each level
//are sorted until 2*levels
//Inverse is to store inverse of suffix array
int levels[MAXP][MAXN],inv[MAXN];


//Node of suffix array which will store index and 2 ranks
//of first and second half
class Node {
public:
    int idx;
    int rnk[2];
};

//Suffix array
Node suffix[MAXN];

//Number of steps or power of 2 and length of string
int step,N;

//Compare function to compare two Nodes
bool compare(Node &a,Node &b) {
    return a.rnk[0]==b.rnk[0]?(a.rnk[1] < b.rnk[1]):(a.rnk[0] < b.rnk[0]);
}

//Find the suffix array
void suffixArray(string &str) {

    //Put in first level the simple ASCII values of string
    //First comparison will be on the basis of these
    for(int i=0;i<str.length();i++)
        levels[0][i] = str[i];

    //Loop till the power of 2 which is largest than string
    step=1,N = str.length();
    for(int i=1; i>>1 < N ; i<<=1,step++) {

        //Loop over all suffixes
        for(int j=0;j<N;j++) {

            //First half will be the first rank the one which we have already sorted
            suffix[j].rnk[0] = levels[step-1][j];

            //Next half will be second rank and other suffix which we have already sorted
            //in previous step for this k = 4, 2 and 2 length strings are already sorted
            suffix[j].rnk[1] = (j+i)<N?levels[step-1][j+i]:-1;

            //Store the current index as it will change after sorting
            suffix[j].idx = j;
        }

        //Sort the suffix array according to the ranks
        sort(suffix,suffix+N,compare);

        //Now add new ranks of this level to each suffix
        for(int j=0;j<N;j++) {

            //If the current suffix has same rank as previous one then do not increase its rank
            //Else increase it or make it equal to current j.
            levels[step][suffix[j].idx] = i>0&&(suffix[j].rnk[0]==suffix[j-1].rnk[0]&&
                                    suffix[j].rnk[1]==suffix[j-1].rnk[1])?levels[step][suffix[j-1].idx]:j;
        }
    }
}

//Find the longest common prefix of two suffixes using
//suffix array
int lcp(int x,int y) {

    //if both are less than x return
    if(x < 0 || y < 0)
        return 0;

    //Loop until the power becomes 0 or numbers become greater than length
    //As extreme cases in search of binary search
    int res = 0;
    for(int k=step-1;k>=0 && x < N && y < N;k--) {

        //If the prefixes at current power are equal
        //Increase the x and y values after the equal
        //prefixes. if they are at 0 and 0 and k is 4
        //increase than to 4 and 4 as first 4 characters are equal
        //According to level,now find the next 2 one if they are
        //equal or not.
        if(levels[k][x] == levels[k][y])
            x += 1<<k, y += 1<<k, res += 1<<k;
    }

    //return the result
    return res;
}

int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    string str;
    while(t--) {

        //Take the string
        cin>>str;

        //Initialize all variables
        memset(levels,0,sizeof(levels));
        memset(suffix,NULL,sizeof(suffix));
        memset(inv,0,sizeof(inv));
        step =0;

        //Find the suffix array
        suffixArray(str);

        //Find the inverse of suffix array
        for(int i=0;i<N;i++)
            inv[levels[step-1][i]] = i;

        //Now find the lcp of consecutive suffixes
        //As it will give how many characters can make distinct
        //substring. for example in a and aba lcp will be 1 as
        //1 character matches. now rest ba can for substring b and ba.
        int tot = N - suffix[0].idx;
        for(int i=1;i<N;i++) {

            //Subtract from total length of current suffix the lcp of this and previous one
            tot += (N - suffix[i].idx) - lcp(inv[i-1],inv[i]);
        }

        //print the result
        cout<<tot<<endl;
    }
}
