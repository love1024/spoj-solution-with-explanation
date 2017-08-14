#include<bits/stdc++.h>

using namespace std;

//Node to store start and end of
//each input
class Node {
public:
    int s;
    int e;
    Node(int s,int e) {
        this->s = s;
        this->e = e;
    }
};

//Function to compare input by starting
//point and ending point
bool compare(Node &a,Node &b) {
    if(a.s == b.s)
        return a.e < b.e;
    else
        return a.s < b.s;
}


int main() {

    //Take number of test cases
    int t,n,s,e;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number of inputs
        cin>>n;

        //Take all inputs
        vector<Node> vec;
        for(int i=0;i<n;i++) {
            cin>>s>>e;
            vec.push_back(Node(s,e));
        }

        //Sort input according to their starting point
        sort(vec.begin(),vec.end(),compare);

        //Initialize starting point to first input
        //and count to 1
        int st = vec[0].s, en = vec[0].e, cnt = 1;
        for(int i=1;i<vec.size();i++) {

            //Take the current input starting and end
            int cs = vec[i].s, ce = vec[i].e;

            //If the current starting point is before the ending
            //point of the last input and the running time of current input
            //is less than the remaining time of previous input then we can replace
            //them
            if(cs < en && (ce-cs) < (en-cs)) {
                st = cs;
                en = ce;
            }
            //If the current starting point is greater than ending point of previous one
            //Then increase the count and replace with current input
            else if(cs >= en) {
                st = cs;
                en = ce;
                cnt++;
            }
        }

        //Print the answer
        cout<<cnt<<endl;
    }

}
