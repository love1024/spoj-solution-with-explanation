#include<bits/stdc++.h>

using namespace std;

//Number of children of each node in Trie
const int SIZE = 10;

//Structure for trie
class Trie {
public:

    //Pointer to children
    Trie* childs[SIZE];

    //If current node is leaf
    bool isLeaf;

    //Initialize variables
    Trie() {
        isLeaf = false;
        for(int i=0;i<SIZE;i++)
            childs[i] = NULL;
    }
};

//Insert string in trie if there is no other prefix string
//before it
bool insertInTrie(Trie *trie,string str) {

    //Loop over all characters of string
    for(int i=0;i<str.length();i++) {

        //Take current index of child
        int cur = str[i] - '0';

        //If it is NULL insert new child
        if(trie->childs[cur] == NULL) {
            Trie *temp = new Trie();
            trie->childs[cur] = temp;
        }

        //Move to the  child
        trie = trie->childs[cur];

        //if it is leaf then a prefix string already
        //exist so return false
        if(trie->isLeaf)
            return false;
    }

    //Mark this as leaf node
    trie->isLeaf = true;

    //Return true if success
    return true;
}

int main() {

    //Take number of test cases
    int t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number of phone contacts
        cin>>n;

        //Take all phone contacts
        vector<string> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];

        //Sort number lexographically
        sort(vec.begin(),vec.end());

        //Variable to donate if we can insert the string
        bool canInsert = true;

        //Root of all trie
        Trie *t = new Trie();

        //Loop over all phone contacts
        for(int i=0;i<n;i++) {

            //Try to insert current string in trie
            //And check the result if already a prefix is present or not
            bool res = insertInTrie(t,vec[i]);

            //If we cannot insert then break
            if(!res) {
                canInsert = false;
                break;
            }
        }

        //Print result accordingly
        if(canInsert)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
