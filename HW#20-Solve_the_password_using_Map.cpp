// Shitrit, Jonathan
// CS211 section 52 Homework #20
#include<iostream>
#include<map>
#include<vector>

using namespace std;

// Returns the password (you may assume that there is only 1 correct answer)
string findPassword(vector<string> &papers) {
    vector<string> in = papers;

    //examples are based on this vector: {"011", "0111", "01110", "111", "0111", "10111"};
    
    int num_frags = in.size(); // size of the vector string ex: 6
    int num_bits = 0;
    for(string i:in)
        num_bits += i.length(); // assigns num_bits to the length of all the strings ex: 24
    
    int num_files = num_frags / 2; // num_files = half of num_frags ex: 3
    int file_size = num_bits / num_files; // figures out the length of the password by dividing the number of bits by the number of files ex: 24 / 3 => 8
    
    map<string, int> d;
    
    for(string i:in)
        for(string j:in){
            string s = i + j;
            if (s.size() == file_size){ // checks if s.size = 8 (length of password)
                if(d.find(s) == d.end()){ // checks if map d doesnt have the same element s
                    d[s] = 1; // if it doesnt give that key value pair a 1
                }
                else{
                    d[s]++; // if it does then increment that key value pair. Meaning the pair that has incremented the highest is the password
                }
            }
        }
    
    // find the max element of the map
    int max = 0;
    string val;
    
    for (auto i:d){  // i is a pair
        if(i.second > max){
            val = i.first;
            max = i.second;
        }
    }
    return val;
}

int main() {
    cout << "Your password:\tCorrect password:" << endl;
    
    vector<string> papers1 = {"011", "0111", "01110", "111", "0111", "10111"};
    cout << findPassword(papers1) << " \t01110111" << endl;
    
    vector<string> papers2 = {"011", "0110", "01100", "100", "1100", "01101"};
    cout << findPassword(papers2) << " \t01101100" << endl;
    
    vector<string> papers3 = {"01", "01", "1001", "0100", "010010", "001001"};
    cout << findPassword(papers3) << " \t01001001" << endl;
    
    vector<string> papers4 = {"0010", "001", "100", "0100"};
    cout << findPassword(papers4) << " \t0010100" << endl;
    
    vector<string> papers5 = {"1100", "110", "0101", "101"};
    cout << findPassword(papers5) << " \t1100101" << endl;
    
    vector<string> papers6 = {"1010", "0011", "011", "101"};
    cout << findPassword(papers6) << " \t1010011" << endl;
}
