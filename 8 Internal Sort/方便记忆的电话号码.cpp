#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map<string, int> mp;

void insert(const string& str){
    string res;
    int cnt = 0;
    for (char c: str){
        if (c == '-') continue;
        else if (c >= 'A' && c < 'Q') res += '2'+(c-'A')/3;
        else if (c > 'A' && c < 'Z') res += '2'+(c-'A'-1)/3;
        else res += c;
        if (++cnt == 3) res += '-';
    }
    ++mp[res];
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string str;
    cin >> n;
    while (n--){
        cin >> str;
        insert(str);
    }
    
    bool f = false;
    for (const auto& t: mp){
        if (t.second == 1) continue;
        f = true;
        cout << t.first << " " << t.second << endl;
    }
    if (!f) cout << "No duplicates." << endl;
}
