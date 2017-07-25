#include<bits/stdc++.h>

using namespace std;

int main() {

    //Variables for number of friends,friend id and number of friends of friend
    int n,f,m;

    //Take number of friends
    cin>>n;

    //Take set for unique ids
    set<int> st;

    //Loop over all friends
    for(int i=0;i<n;i++) {

        //Take friend id and number of friends of friend
        cin>>f>>m;

        //Insert current friend id
        st.insert(f);

        //Traverse all friends of friend and insert them
        //Set will automatically keep the unique so no duplicate
        for(int i=0;i<m;i++) {
            cin>>f;
            st.insert(f);
        }
    }

    //Print friend of friends by subtracting his direct friends
    cout<<st.size() - n<<endl;
}
