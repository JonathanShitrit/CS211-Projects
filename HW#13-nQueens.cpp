// Shitrit, Jonathan
// CS211 section 52 Homework #13
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
    if(c == -1){
        exit(1);
    }
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
    int n,j;
    cout << "Enter a number for the N-Queens problem.\n";
    cin >> n;

    for(int i = 1; i <= n; i++){
        int *q = new int[i]; //dynamically allocate array of size i
        q[0] = 1;
        int count = -1;
        int c = 0;
        
        bool from_backtrack=false;
        // The outer loop keep looking for solutions
        // The program terminates from function backtrack
        // when we are forced to backtack into column -1
        while(true){
            
            while(c<i){
                // if we just returned from backtrack, use current value of row
                // otherwise get ready to start at the top of this column
                
                if(!from_backtrack)
                    q[c] = -1; // we did not just return from backtrack
               
                from_backtrack = true;
                
                while(q[c] < i){//this loop repeats i times for the rows
                    q[c]++;
                    // backtrack and continue the loop in the previous column

                    if(q[c] == i){//if it reaches i, then there is no solution, so we go backa  column to fix it
                        from_backtrack = true;
                        c--;
                        break;
                    }
                    
                    if(tests(q,c)){
                        from_backtrack = false;
                        c++;
                        break;
                    }
                    
                }
                if(c == -1) break;
            }
            
            count++;
            c--;
            from_backtrack = true;
            if(c <= -1) break; //if its less then -1, then its time to exit the while loop
            
        }
        delete [] q;
        cout << "There are " << count << "solutions to the "  << i << "queens." << endl;

    }
    return 0;
    
}



