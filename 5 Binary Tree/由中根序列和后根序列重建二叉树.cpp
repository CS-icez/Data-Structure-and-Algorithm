#include <iostream>
using namespace std;

const int N = 65536+10;
int in[N], post[N], n;

void read(){
    cin >> in[0];
    do{
        cin >> in[++n];
    } while (in[n] != in[0]);
    post[0] = in[0];
    for (int i = 1; cin >> post[i]; ++i);
}

void solve(int li, int lp, int len){
    if (len < 0) return;
    cout << post[lp+len] << " ";
    int len1 = 0;
    while (in[li+len1] != post[lp+len]) ++len1;
    solve(li, lp, len1-1);
    solve(li+len1+1, lp+len1, len-len1-1);
}

int main(){
    read();
    solve(0, 0, n-1);
}
