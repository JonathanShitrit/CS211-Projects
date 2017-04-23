// Shitrit, Jonathan
// CS211 section 52 Homework #5
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool tests(int q[], int c){
    
    for(int i = 0; i < c; i++){
        
        if((q[i] == q[c]) || (abs(q[c] - q[i]) == (c - i)))
        {
            return false;
        }
    }
    return true;
}

void backtrack(int &c){
    c--;
    if(c == -1)
        exit(1);
}

void print(int q[]){
    
    static int count = 0;
    int i, j, board[8][8] = {0};
    count++;
    
    cout << "Solution # " << count << endl;
    
    for(i = 0; i < 8; i++)
    {
        board[q[i]][i] = 1;
    }
    
    for(i = 0; i < 8; i++) // print boards
    {
        for(j = 0; j < 8; j++)
            cout << board[i][j] << " ";
        
        cout << endl;
    }
    
}

int main(){
    
    int q[8]; q[0] = 0;
    int c = 1;
    // from_backtrack keeps track if we need to reset the row to the top of the current colum or not.
    
    bool from_backtrack = false;
    // The outer loop keep looking for solutions
    // The program terminates from function backtrack
    // when we are forced to backtack into column -1
    
    while(true){
        
        while(c < 8){
            // if we just returned from backtrack, use current value of row
            // otherwise get ready to start at the top of this column
            if(!from_backtrack) // we did not just return from backtrack
                q[c] = -1;
            
            from_backtrack = false;
            
            while(q[c] < 8){ // place queen in this column
                q[c]++;
                // backtrack and continue the loop in the previous column

                while(q[c] == 8)
                {
                    backtrack(c);
                    q[c]++;
                }
                // if this position is ok, place the queen
                // and move on (break) to the next column,
                // otherwise keep looking in this column
                
                if(tests(q, c))
                    break;
                
            }
            c++; // placed queen
        }
        
        // print solution
        print(q);
        backtrack(c);
        from_backtrack = true;
        
    }
    
}

