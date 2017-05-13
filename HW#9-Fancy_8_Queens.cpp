// Shitrit, Jonathan
// CS211 section 52 Homework #9
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
    
    int i, j, k, l, r, c;
    typedef wchar_t box[5][7];
    box bb, wb, *board[8][8];
    count++;
    
    // initialize the black and white queens to their unique 2D values
     box bq = { {'A','A','A','A','A','A','A'},
                {'A',' ','A',' ','A',' ','A'},
                {'A',' ',' ',' ',' ',' ','A'},
                {'A',' ',' ',' ',' ',' ','A'},
                {'A','A','A','A','A','A','A'}
    };
    
    box wq = {  {' ',' ',' ',' ',' ',' ',' '},
                {' ','A',' ','A',' ','A',' '},
                {' ','A','A','A','A','A',' '},
                {' ','A','A','A','A','A',' '},
                {' ',' ',' ',' ',' ',' ',' '}
    };
    
    //fill in bb=black box and wb=whitebox
    for(i=0;i<5;i++)
        for(j = 0; j < 7; j++){
            wb[i][j] = ' ';
            bb[i][j] = 'A';// L'\u2588'
        }
    
    //fill board with pointers to bb and wb in alternate positions
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++){
            
            if((i + j) % 2 == 0) { // if the row + column is even put a black box or black queen

                if(q[i] == j){ // if the 1D array's row equals to the column then put a black queen since we are in the even row + column
                    board[i][j] = &bq;
                }
                else {
                    board[i][j] = &bb;
                }
            }
            else { // if the row + cloumn is odd put a white box or white queen

                if(q[i] == j){ // if the 1D array's row equals to the column then put a white queen since we are in the odd row + column
                    board[i][j] = &wq;
                }
                else {
                    board[i][j] = &wb;
                }

            }
        }
    }
    
    cout << "Solution # " << count << endl;
    
    // print the board via the pointers in array board
    // first print upper border
    cout << " ";
    for(i = 0; i < 7 * 8; i++)
        cout<<'_';
    cout << endl;

    for(i=0;i<8;i++)
        for(k = 0; k < 5; k++)
        {
            cout << " " << '|'; //print left border
            for(j = 0; j < 8; j++)
                for(l = 0; l < 7; l++)
                    cout << *(board[i][j])[k][l];
            cout<<'|' << endl; // at end of line print bar and then newline
        }
    
    //before exiting print lower border
    cout<<" ";
    for(i = 0; i < 7 * 8; i++)
        cout << '^';
    cout << endl;
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

