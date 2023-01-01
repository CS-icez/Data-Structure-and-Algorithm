#include <iostream>
#include <set>
#include <utility>
#include <string>
using namespace std;

set<pair<string, int>> s;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    int n, m;
    cin >> n;
    
    for (int i = 1, tot; i <= n; ++i){
        cin >> tot;
        while (tot--){
            cin >> str;
            s.insert({str, i});
        }
    }
    
    cin >> m;
    while (m--){
        cin >> str;
        auto p = s.upper_bound({str, 0});
        if (p == s.end() || p->first != str)
            cout << "NOT FOUND" << endl;
        
        else{
            for (; p->first == str; ++p)
                cout << p->second << " ";
            cout << endl;
        }
    }
}
