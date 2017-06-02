// Shitrit, Jonathan
// CS211 section 52 Homework #16

#include <iostream>
#include <cmath>

using namespace std;

bool tests(int* q, int c, int n){
    
    for(int i = 0; i < c; i++)
        if((q[i]/n) + (q[i]%n) == (q[c]/n) + (q[c]%n) || ((q[i]/n) - (q[i]%n) == (q[c]/n) - (q[c]%n)))
            return false;
    return true;
}

int factorial(int n) {
    if(n == 1) return 1;
    return n * factorial(n-1);
}

void backtrack(int &c, int count, int n, int k, int q[]){
    c--;
    if(c == -1){
        cout << "n  |  k  | solutions" << endl <<
                n << "     " << k << "     " << count/factorial(k)<<endl;
        delete[] q;

        exit(1);
    }
}



int main(){
    int n, k, count = 0;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of k: ";
    cin >> k;
    while(n <= 0 || k <= 0){
        cout << "Enter value of n: ";
        cin >> n;
        cout << "Enter value of k: ";
        cin >> k;
    }
    
    int* q = new int[k];
    q[0] = 0;
    int c = 1;
    // from_backtrack keeps track if we need to reset the row to the top of the current colum or not.
    
    bool from_backtrack = false;
    // The outer loop keep looking for solutions
    // The program terminates from function backtrack
    // when we are forced to backtack into column -1
    
    while(true){
        
        while(c < k){
           
            if(!from_backtrack) // we did not just return from backtrack
                q[c] = -1;
            
            from_backtrack = false;
            
            while(q[c] < n*n){
                q[c]++;
                
                if(q[c] == n*n) {
                    backtrack(c, count, n , k, q);
                    from_backtrack = true;
                    continue;
                }
                
                if(tests(q, c, n)){
                    c++;
                    break;
                }
            }
        }
        
        count++;
        backtrack(c, count, n , k, q);
        from_backtrack = true;
        
    }
    return 0;
}


