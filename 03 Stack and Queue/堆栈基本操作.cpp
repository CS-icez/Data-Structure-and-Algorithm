#include <iostream>
#include <string>
#include <stack>
using namespace std;

string res;
int n;
stack<int> stk;

int main(){
    bool f = 1;
    cin >> n;
    for (int i = 1, t, idx = 1; i <= n; ++i){
        cin >> t;
        if (t > n || t < 1){
            f = 0;
            break;
        }
        if (idx <= t){
            for (; idx <= t; ++idx){
                stk.push(idx);
                res += "PUSH "+to_string(idx)+"\n";
            }
            stk.pop();
            res += "POP "+to_string(t)+"\n";
        }
        else{
            if (stk.top() == t){
                stk.pop();
                res += "POP "+to_string(t)+"\n";
            }
            else{
                f = 0;
                break;
            }
        }
    }
    cout << (f? res: "NO") << endl;
}
