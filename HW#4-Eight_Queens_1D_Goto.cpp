// Shitrit, Jonathan
// CS211  Section 52 Homework 4
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int q[8] = {0}, r = 0, c = 0, solutionNum = 1;
    
    q[0] = 0;
    
next_col:
    c++;
    if(c == 8) goto print;
    
    q[c] = -1;
    
next_row:
    q[c]++;
    
    if(q[c] == 8) goto backtrack;
    
    // row test
    for(int i = 0; i < c; i++)
        if((q[i] == q[c]) || ((c - i) == abs(q[c] - q[i]))) goto next_row;

    goto next_col;
    
backtrack:
    c--;
    if(c == -1) return 0;
    
    goto next_row;
    
print:
    cout << "Solution " << solutionNum << endl;
    for (int a = 0; a <= 7; a++) {
        for (int d = 0; d <= 7; d++) {
            if(q[a] == d)
                cout << "1";
            else {
                cout <<"0";
            }
        }
        cout << endl;
    }
    
    solutionNum++;
    goto backtrack;
    
}
