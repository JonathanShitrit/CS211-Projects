// Shitrit, Jonathan
// CS211  Section 52 Homework 3
#include <iostream>

using namespace std;

int main(){
    int b[8][8] = {0}, r, c = 0, i, solutionNum = 1;
    
    b[0][0] = 1;
    
next_col:
    c++;
    if(c == 8) goto print;
    
    r = -1;
    
next_row:
    r++;
    
    if(r == 8) goto backtrack;
    
    // row test
    for(i = 0; i < c; i++)
        if(b[r][i] == 1) goto next_row;
    
    // up diagnol test
    for(i = 1; (r - i) >= 0 && (c - i) >= 0; i++)
        if(b[r-i][c-i] == 1) goto next_row;
    
    // down diagnol test
    for(i = 1; (r + i) < 8 && (c - i) >= 0; i++)
        if(b[r+i][c-i] == 1) goto next_row;
    
    b[r][c] = 1;
    goto next_col;
    
backtrack:
    c--;
    if(c == -1) return 0;
    
    r = 0;
    while (b[r][c] != 1) r++;
    b[r][c] = 0;
    goto next_row;
    
print:
    cout << "Solution " << solutionNum++ << endl;
    for (int a = 0; a <= 7; a++) {
        for (int d = 0; d <= 7; d++) {
            cout << b[a][d] << " ";
        }
        cout << endl;
    }
    
    goto backtrack;
    
}
