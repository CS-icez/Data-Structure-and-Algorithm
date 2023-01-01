#include <iostream>
#include <string>
using namespace std;

string s, t, res;

int main(){
    while (getline(cin, t)) s += t, s += '\n';
    
    for (int i = 0, len = s.length(); i < len; ++i){
        if (s[i] == '/' && s[i+1] == '*'){
            for (; s[i-1] != '*' || s[i] != '/'; ++i);
        }
        else if (s[i] == '"'){
            for (res += s[i++]; s[i-1] == '\\' || s[i] != '"'; res += s[i++]);
            res += s[i];
        }
        else if (s[i] == '\''){
            for (res += s[i++]; s[i-1] == '\\' || s[i] != '\''; res += s[i++]);
            res += s[i];
        }
        else res += s[i];
    }
    
    cout << res << endl;
}
