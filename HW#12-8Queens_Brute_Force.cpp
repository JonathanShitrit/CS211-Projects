// Shitrit, Jonathan
// CS211  Section 52 Homework 12
#include<cmath>
#include<iostream>

using namespace std;
bool ok(int b[8][8]){
    //test
    int i, r, c;
    for(c = 0; c < 8; c++){
        r = 0;
        while(b[r][c] != 1)
            r++;//find the first queen in the column
        
        for(i = 0; i < c; i++){ // row test
            if(b[r][i] == 1) return false;
        }
        
        for(i = 1; ((r-i) >= 0 && (c-i) >= 0); i++){ // up diagnol
            if(b[r-i][c-i] == 1) return false;
        }
        
        for(i = 1; ((r+i) < 8 && (c-i) >= 0); i++){ // down diagnol
            if(b[r+i][c-i] == 1) return false;
        }
    }
    return true; // The board is ok, return true
}

void print(int b[8][8], int count){
    
    cout << "Solution " << count << endl;

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            cout << b[r][c] << " ";
        }
        cout << endl;
    }
    
}

int main(){
    int board[8][8] = {0};
    int count = 0;
    
    for(int i0 =0; i0 <8; i0 ++)
        for(int i1 =0; i1 <8; i1 ++)
            for(int i2 =0; i2 <8; i2 ++)
                for(int i3 =0; i3 <8; i3 ++)
                    for(int i4 =0; i4 <8; i4 ++)
                        for(int i5 =0; i5 <8; i5 ++)
                            for(int i6 =0; i6 <8; i6 ++)
                                for(int i7 =0; i7 <8; i7 ++){
                                    // use the indices of the loops to set a configuration in array board ...
                                    board[i0][0] = 1; // only the row columns increment in the for loops
                                    board[i1][1] = 1;
                                    board[i2][2] = 1;
                                    board[i3][3] = 1;
                                    board[i4][4] = 1;
                                    board[i5][5] = 1;
                                    board[i6][6] = 1;
                                    board[i7][7] = 1;
                                    // if this configuration is conflict-free, print the count and the board
                                    if(ok(board))
                                        print(board, ++count);
                                    // reset the board for the next configuration ...
                                    for(int i = 0; i < 8; i++){ //clears the board
                                        for(int j = 0; j < 8; j++){
                                            board[i][j] = 0;
                                        }
                                    }
                                }
    return 0;
}
