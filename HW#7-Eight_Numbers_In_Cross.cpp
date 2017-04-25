// Shitrit, Jonathan
// CS211 section 52 Homework #7
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool tests(int q[], int c){
    int a[][5] = {
                {-1},
                {0, -1},
                {0, 1, -1},
                {0, 2, -1},
                {1, 2, -1},
                {1, 2, 3, 4, -1},
                {2, 3, 5, -1},
                {4, 5, 6, -1}
    };
    
    for(int i = 0; i < c; i++)
    {
        if(q[i] == q[c])
        {
            return false;
        }
    }
    
    for(int i = 0; a[c][i] != -1; i++){
        if ( abs(q[c] - q[a[c][i]]) == 1 ) return false;
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
    
    cout << " " << q[1] << " " << q[4] << " " << endl;
    cout << q[0] << " " << q[2] << " " << q[5] << " " << q[7] << endl;
    cout << " " << q[3] << " " << q[6] << " " << endl;


}

int main(){
    
    int q[8]; q[0] = 0;
    int c = 1;
    // from_backtrack keeps track if we need to reset the row to the top of the current colum or not.
    
    bool from_backtrack = false;
    
    while(true){
        
        while(c < 8){
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

