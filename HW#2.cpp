// Shitrit, Jonathan
// CS211  Section 52 hw 2
#include <iostream>

using namespace std;

// a = [1, 2, 3, 4, 5]
// b = [3, 4, 5, 1, 2]

bool equivalent(int a[], int b[], int n) {
    int temp = 0;
    
    // goes into a loop that continues if the shifted array's first element, b[0], is equal to the not shifted array's first element, a[0].
    while(b[0] != a[0]){
        // temperary = holds on to the last element in array a.
        temp = a[n - 1];
        for (int i = n - 1; i > 0; i--) {
            // element of a[i] equals to the element that is one position before a[i].
            a[i] = a[i - 1];
        }
        // assign the first position to the last element before the new shift.
        a[0] = temp;
    }

    // compare both arrays
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) // if one element is not equal to the other then it is impossible to be shift
                          // equivalent so return false
            return false;
    }
    // return true if never returned false, must be shift equivalent
    return true;
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {3, 4, 5, 1, 2};
    
     if function returned true that means its shift equivalent
    if (equivalent(a, b, 5)){
        cout << "The arrays are shift equivalent.\n";
    }
    else{
        cout << "The arrays are NOT shift equivalent.\n";
    }
    
    return 0;
    
}
