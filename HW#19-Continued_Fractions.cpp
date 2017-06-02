// Shitrit, Jonathan
// CS211 section 52 Homework #17
// Continued fractions
#include <iostream>
using namespace std;


class Rat{
    
private:
    int n;
    int d;
public:
    // constructors
    // default constructor
    Rat(){
        n=0;
        d=1;
    }
    // 2 parameter constructor
    Rat(int i, int j){
        n=i;
        d=j;
    }
    // conversion constructor
    Rat(int i){
        n=i;
        d=1;
    }
    //accessor functions (usually called get() and set(...) ) int getN(){ return n;}
    int getD(){
        return d;
    }
    void setN(int i){
        n=i;
    }
    void setD(int i){
        d=i;
    }
    //arithmetic operators
    //add
    Rat operator+(Rat r){
        Rat t;
        t.n = n*r.d+d*r.n;
        t.d = d*r.d;
        return t;
    }
    //subtract
    Rat operator-(Rat r){
        Rat t;
        t.n = n*r.d-d*r.n;
        t.d = d*r.d;
        return t;
    }
    //multiply
    Rat operator*(Rat r){
        Rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        return t;
    }
    //divide
    Rat operator/(Rat r){
        Rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        return t;
    }
    
    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

int gcd(int n, int d){
    if (d==0)return n;
    return gcd(d, n%d);
}

Rat reduce(int &i, int &j){//this function reduces r.d and r.n accordingly so it can be used
    for(int a = i; a > 0; a--){
        if(i % a == 0 && j % a == 0){
            i = i / a;
            j = j / a;
            break;
        }
    }
    return Rat(i,j);
}

// operator<<() is NOT a member function but since it was declared a friend of Rat // it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
    if(r.n >= r.d){ //if the numerator is greater than the denominator it is an improper fraction, it must be reduced
        if(r.n % r.d == 0){
            os << r.n / r.d << endl;
        } else {
            int x = gcd(r.n%r.d,r.d); //just in case the reduced fraction needs to be reduced further
            os << r.n / r.d << " " << (r.n%r.d) / x << " / " << (r.d) / x << endl;
        }
    } else if(r.n == 0){
        os << r.n << endl;//if the numerator is 0, then return 0
    } else {
        int x = gcd(r.n%r.d,r.d);//reduce the proper fraction
        os << r.n / x << " / " << r.d/ x << endl;
    }
    
    return os;
}
// operator>>() is NOT a member function but since it was declared a friend of Rat // it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
    reduce(r.n,r.d);//reduce the numbers before using them
    return is;
}

double first(int a[], int size){
    if(size == 0) return a[0];
    
    double x = 0.0;
    
    x = double(a[0]) + (1.0 /  first(a + 1, size - 1));

    return x;
}

int* second(int a[], int size){
    int* v = new int[2];
    //base case
    if(size == 1){
        v[0] = a[0];
        v[1] = 1;
        return v;
    }
    
    //general case
    int* frac = second(a + 1, size - 1);
    int p = frac[0];
    int q = frac[1];
    delete[] frac;
    
    v[0] = (a[0] * p) + q;
    v[1] = p;
    return v;
}

Rat third(int a[], int size){
    int* v = second(a, size);
    
    Rat r(v[0], v[1]); //converts to rat to be simplified
    return r;
}



int main(){
    int a[] = {1, 2, 3, 4};
    
    cout << "Continued fractions 1: " <<
    first(a, 4) << endl;
    
    int* r = second(a, 4);
    cout<< "Continued fraction 2: " << r[0]<<"/"<<r[1]<<endl;
    delete[] r;
    
    cout<< "Continued fraction 3: " << third(a, 4);
}



 

