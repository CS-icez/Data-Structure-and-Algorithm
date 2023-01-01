#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6+10;
int nxt[N], len;
char s[N];

int main(){
    for (; ;){
        scanf("%s", s+1);
        if (s[1] == '.' && !s[2]) break;
        
        len = strlen(s+1);
        for (int i = 2, j = 0; i <= len; ++i){
            while (j && s[i] != s[j+1]) j = nxt[j];
            if (s[i] == s[j+1]) ++j;
            nxt[i] = j;
        }
        
        int k = nxt[len];
        cout << (len%(len-k)? 1: len/(len-k)) << endl;
    }
}
