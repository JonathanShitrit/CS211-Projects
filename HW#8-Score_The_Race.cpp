
// Shitrit, Jonathan
// CS211 section 52 Homework #8
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

bool valid(string race){
    int z = 0, amountOfTeams = 0;
    double  numberOfRunners = 0.0;
    
    for(int i = 0; i < race.length(); i++){
        if(!(race[i] >= 65 && race[i] <= 90)){ // if the ascii value is not in between A and Z return
                                               //false.
            return false;
        }
        
        if(race[i] == race[i + 1]){// if the first char equals to another than add to the amount of
                                   //teams there are.
            amountOfTeams++;
        }
    }
    
    // the number of runners equals to the race lenght / amount of runners.
    numberOfRunners = double(race.length()) / double(amountOfTeams);
    z = numberOfRunners;

        // if the number of runners of the race isnt the same for each team, than numberOfRunners would be a decimal and int z wouldnt be equal to a decimal. Which means there isnt the same amount of runners for each team.
    if(z != numberOfRunners){
        return false;
    }
    else {
        // if z = to numberOfRunners than number of runners is the same for each team, return true.
        return true;
    }

}

string get_teams(string race){
    string amountOfTeams = "";

    for(int i = 0; i < race.length(); i++){
        // if there is a character in amountOfTeams that has an ASCII value greater than the race.size
        if(amountOfTeams.find(race[i]) > race.size()){
            // then add the character to the string of AmountOfTeams
            amountOfTeams = amountOfTeams + race[i];
            
        }
    }
    // Sort amountOfTeams
    sort(amountOfTeams.begin(), amountOfTeams.end());
    return amountOfTeams;
}

double score(string race, char c){
    double  sum = 0.0;
    int amountOfTeams = 0;
    
    for(int i = 0; i < race.length(); i++){
        // starts at the alphabetically first letter
        if(race[i] == c){
            // add the position to sum + 1 because i starts at 0
            sum += i + 1;
            amountOfTeams++;
        }
    }
    
    // return the sum / amount of teams which = the score
    return double(sum) / double(amountOfTeams);
}

int main(){
    string race,teams;
    cout << "Please enter the results of the race: ";
    cin >> race;
    // Check that the race is valid, and each team has the same number
    //of members. Write a function bool valid(string race). Do the input in a loop.
    while(!valid(race)){
        cout << "Enter the results of the race again: ";
        cin >> race;
    }
    
    teams = get_teams(race); // teams in sorted order

    cout << "\nThere are " << teams.length() << " teams." << endl << endl;
    cout << "Each team has " << race.length() / teams.length() << " runners." << endl << endl;
    //teams and scores
    cout << '\t' << "Team" << '\t' << "Score" << endl << endl;

    double min_score = score(race,teams[0]);
    for(int i = 0; i < teams.length(); i++){
        char c = teams.at(i);
        double s = score(race,c);
        cout << '\t' << c << '\t' << score(race,c) << endl;
        
        if(s < min_score)
            min_score = s;
    }
    
    cout << endl << "min score= " << min_score << endl;
    system("pause");
}
