#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

const int N = 666;
int son[N][26], top;
set<string> s[N];

void insert(const string& str){
    string t = str;
    sort(t.begin(), t.end());
    int p = 0;
    for (char c: t){
        if (!son[p][c-'a']) son[p][c-'a'] = ++top;
        p = son[p][c-'a'];
    }
    s[p].insert(str);
}

int search_trie(const string& str){
    int p = 0;
    for (char c: str){
        if (!son[p][c-'a']) return 0;
        p = son[p][c-'a'];
    }
    return p;
}

int main(){
    string str;
    string e = "XXXXXX";
    s[0].insert("NOT A VALID WORD");
    
    while (cin >> str, str != e)
        insert(str);
    
    int x;
    while (cin >> str, str != e){
        sort(str.begin(), str.end());
        x = search_trie(str);
        for (const string& t: s[x])
            cout << t << endl;
        cout << "******" << endl;
    }
}
