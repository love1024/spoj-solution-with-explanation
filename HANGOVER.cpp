#include<iostream>

using namespace std;

int main() {
    double len,last = 0.00;
    cin>>len;
    while(len != last) {
        double cur = 0.5;
        int cnt = 1;
        while(cur < len) {
            cur = cur + 1.0/(cnt+2);
            cnt++;
        }
        cout<<cnt<<" card(s)"<<endl;
        cin>>len;
    }
}
