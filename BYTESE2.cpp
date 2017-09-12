#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Node to store
//the position of entering or leaving
//type to represent leaving or entering
class Node {
public:
    int pos,type;
    Node(int pos,int type) {
        this->pos = pos;
        this->type = type;
    }
};

//To Compare two nodes
bool compare(Node &a,Node &b) {
    return a.pos < b.pos;
}

int main() {
    //Take number of test cases
    int t,n,a,b;
    cin>>t;

    //Loop over all test cases
    while(t--) {
        cin>>n;

        //Take position of entering and leaving
        //and store in node
        vector<Node> vec;
        for(int i=0;i<n;i++) {
            cin>>a>>b;
            vec.push_back(Node(a,0));
            vec.push_back(Node(b,1));
        }

        //Sort the nodes according to entering position
        sort(vec.begin(),vec.end(),compare);

        //Now Find maximum persons inside in some time interval
        int cnt = 0,mx=0;
        for(int i=0;i<vec.size();i++) {

            //Increase or decrease if person leave or enter
            if(vec[i].type == 0)
                cnt++;
            else
                cnt--;

            //Check if this count is maximum
            mx = max(mx,cnt);
        }
        cout<<mx<<endl;
    }
}
