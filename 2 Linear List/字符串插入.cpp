#include <iostream>
using namespace std;

char ori[22], sub[22];

int main(){
    while (cin >> ori >> sub){
      int idx = 0;
      for (int i = 0; ori[i]; ++i)
          if (ori[i] > ori[idx]) idx = i;
      ++idx;
      char c = ori[idx];
      ori[idx] = 0;
      cout << ori << sub;
      ori[idx] = c;
      cout << ori+idx << endl;
    }
}
