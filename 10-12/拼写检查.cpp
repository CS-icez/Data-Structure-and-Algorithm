#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;

unordered_set<string> s;
unordered_map<string, int> mp;
int timer;

struct S{
    string str;
    bool operator<(const S& t) const{
        return mp[str] < mp[t.str];
    }
};

set<S> res;

void solve(const string& str){
    res.clear();
    string t = str;
    
    for (unsigned i = 0; i < str.length(); ++i){
        for (char c = 'a'; c <= 'z'; ++c){
            t[i] = c;
            if (s.count(t)) res.insert({t});
        }
        t[i] = str[i];
    }
    
    for (unsigned i = 0; i < str.length(); ++i){
        t = str;
        t.insert(i, "0");
        
        for (char c = 'a'; c <= 'z'; ++c){
            t[i] = c;
            if (s.count(t)) res.insert({t});
        }
    }
    
    t = str;
    t += "0";
    for (char c = 'a'; c <= 'z'; ++c){
        t.back() = c;
        if (s.count(t)) res.insert({t});
    }
    
    for (unsigned i = 0; i < str.length(); ++i){
        t = str;
        t.erase(i, 1);
        if (s.count(t)) res.insert({t});
    }
    
    for (const S& ele: res)
        cout << " " << ele.str;
    cout << endl;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    
    while (cin >> str, str != "#"){
        s.insert(str);
        mp[str] = timer++;
    }
        
    while (cin >> str, str != "#"){
        if (s.count(str))
            cout << str << " is correct" << endl;
        else{
            cout << str << ":";
            solve(str);
        }
    }
}
