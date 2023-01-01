#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 1e5+43;
int son[N][26], top;
int cnt[N];
vector<string> v;

void insert(const string& str){
    int p = 0, t;
    for (char c: str){
        t = c-'a';
        if (!son[p][t]) son[p][t] = ++top;
        p = son[p][t];
        ++cnt[p];
    }
}

string prefix(const string& str){
    unsigned i = 0, p = 0;
    for (; i < str.size(); ++i){
        p = son[p][str[i]-'a'];
        if (cnt[p] == 1) break;
    }
    
    return str.substr(0, i+1);
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    while (cin >> str){
        v.push_back(str);
        insert(str);
    }
        
    for (const string& s: v)
        cout << s << " " << prefix(s) << endl;
}
