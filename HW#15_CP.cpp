// Shitrit, Jonathan
// CS211 section 52 Homework #15
// Cross problem
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int * q, int c) {
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

void print(int * q){
    static int count = 0;
    int i, j, board[8][8] = {0};
    count++;
    
    cout << "Solution # " << count << endl;
    
    cout << " " << q[1] << " " << q[4] << " " << endl;
    cout << q[0] << " " << q[2] << " " << q[5] << " " << q[7] << endl;
    cout << " " << q[3] << " " << q[6] << " " << endl;
}

void move(int* q, int i){ // try place in col i
    if(i == 8){
        print(q);
        return;
    }
    for(int j = 0; j < 8; j++){ // j is the row value
        q[i] = j;
        if(ok(q,i)) // try and place a queen in row j of col i,if yes
            move(q,i+1); // go to next column otherwise try next j
    }
}

// no value of j worked so return; };
int main() {
    int q[8];
    move(q,0);
    system("pause");
}


