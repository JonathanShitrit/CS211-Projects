// Shitrit, Jonathan
// CS211 section 52 Homework #17
// NonRecursive shortest path

#include<iostream>
using namespace std;
const int rows = 5;
const int cols = 6;

int minvalue(int left, int up, int down){
    int min = left;
    if(up < min){//check if up is smaller
        min = up;
    }
    if(down < min){//check if down is smaller
        min = down;
    }
    return min;
}

int main(){
    int weight[rows][cols]={
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };
    
    int memo_cost[rows][cols]={0};
    
    //initialize first colum of memo_cost[][]
    for(int i = 0; i < rows; i++){
        memo_cost[i][0] = weight[i][0];
    }
    //fill in rest colum of memo_cost[][]
    for(int c = 1; c < cols; c++){
        for(int r = 0; r < rows; r++){
            int left = weight[r][c] + memo_cost[r][c-1];
            int down = weight[r][c] + memo_cost[(r+1) % rows][c-1];
            int up = weight[r][c] +  memo_cost[(r+4) % rows][c-1];
            
            int min = minvalue(left, up, down);
            
            memo_cost[r][c] = min;
        }
    }
    
    int exit[rows];
    
    for(int i = 0; i < rows; i++)
        exit[i] = memo_cost[i][cols-1];
    // now find the smallest of them
    int min = exit[0];
    int index = 0;
    
    for(int i = 1; i < rows; i++){
        if (min > exit[i]){
            min = exit[i];
            index = i; //places the index of the minimum value in the route
        }
    }
    
    int route[cols] = {-1};
    route[cols-1] = index; //find final step route.
    
    for(int c=cols-2;c>=0;c--){// go backward to find route
        //compare 3 square and find min
        int up = memo_cost[(route[c-1] - 1 + rows) % rows][c];
        int down = memo_cost[(route[c+1] + 1 + rows) % rows][c];
        int left = memo_cost[route[c+1]][c];
        route[c] = minvalue(left, up, down);
    }
    
    //print route
    for(int i=0;i<cols;i++){
        cout<<"route "<<i<<" is: "<<route[i]<<" row."<<endl;
    }
    cout<<"the shortest path is of length "<<min<<endl;
    return 0;
}




