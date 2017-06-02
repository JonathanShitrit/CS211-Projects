// Shitrit, Jonathan
// CS211 section 52 Homework #15
// Cross problem
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

static int mp[3][3] = { {0,2,1},  // Man#0's preferences
    //so man#0 likes woman0 most, woman2 next,and woman1 least
    {0,2,1},  // Man#1's preferences
    {1,2,0}}; // Man#2's preferences

static int wp[3][3] = { {2,1,0},// Woman#0's preferences
    //so woman#0 likes man2 most, man1 next,and man2 least
    {0,1,2},  // Woman#1's preferences
    {2,0,1}}; // Woman#2's preferences


bool ok(int * q, int c) {

    for(int i = 0; i < c; i++)
    {
        int wi = q[i];
        int wc = q[c];
        
        if((q[i] == q[c]) ||
           (mp[i][wc] < mp[i][wi] && wp[wc][i] < wp[wc][c]) ||
           
           (mp[c][wi] < mp[c][wc] && wp[wi][c] < wp[wi][i]))
        {
            return false;
        }
    }

    return true;
}

void print(int * q){
    static int count = 0;
    int i;
    count++;
    
    cout << "Solution # " << count << endl;
    
    cout << "Man - Woman" << endl;
    for(i = 0; i < 3; i++){
        cout << " " << i << " ---- " << q[i] << endl;
    }
    cout<<endl;
    
}

void move(int* q, int i){ // try place in col i
    if(i == 3){
        print(q);
        return;
    }
    for(int j = 0; j < 3; j++){ // j is the row value
        q[i] = j;
        if(ok(q,i)) // try and place a queen in row j of col i,if yes
            move(q, i+1); // go to next column otherwise try next j
    }
}

// no value of j worked so return; };
int main() {
    int q[3];
    move(q,0);
    system("pause");
}


