#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int idx, h1, h2, len;

void dfs(int d1, int d2){
    h1 = max(h1, d1);
    h2 = max(h2, d2);
    
    while (idx < len){
        if (str[idx] == 'd'){
            ++idx;
            dfs(d1+1, ++d2);
        }
        else{
            ++idx;
            return;
        }
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 1; cin >> str, str != "#"; ++i){
        idx = h1 = h2 = 0;
        len = str.length();
        dfs(0, 0);
        cout << "Tree " << i << ": " << h1 << " => " << h2 << endl;
    }
}
