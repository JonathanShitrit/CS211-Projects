# Queens College-CS211-Projects
Algorithmic problem solving using C++

____________________________________________________________________________________________________________________________

HW #2: Equivalent Arrays

Consider the two arrays a and b.
a = {1,2,3,4,5};
b = {3,4,5,1,2};

  It is possible to transform array a into array b by right shifting each element of a to the “right” three places. If an element “falls off” the back of the array have it come around the front and keep counting positions. That is how 3 in array ended up in the first position of array b. One way to look at this is to imagine that we are moving the element around in a circular manner.
  In the example above, we have right shifted the array 3 positions to the right.
Definition: Let a and b be two integer arrays of the same length. We say that they are “shift equivalent” if array a can be right shifted to create array b.
  Problem: Write a function bool equivalent(int a[], int b[], int n) which takes two arrays a and b of length n and returns true is they are shift equivalent and false otherwise.

____________________________________________________________________________________________________________________________

HW #3: Solve the 8 Queens problem using a 2 dimentional array, goto statements, and backtracking.

____________________________________________________________________________________________________________________________

HW #4: Solve the 8 Queens problem using a 1 dimentional array, goto statements, and backtracking.

____________________________________________________________________________________________________________________________

HW #5: Solve the 8 queens problem using a 1 dimensional array program with backtracking REMOVING ALL "GOTOs" - but implementing the same algorithm

____________________________________________________________________________________________________________________________

HW #7: Write a program which allocates the integers 1-8 in a cross, subject to the restrictions that no two adjacent squares contain consecutive integers.
By adjacent we mean vertically, horizontally, or diagonally.

____________________________________________________________________________________________________________________________

HW #8: Score The Race
 Some number of teams are participating in a race. You are not told how many teams are participating but you do know that:
  - Each team has a name, which is one of the uppercase letters A-Z.
  - No two teams have the same name, so there are a maximum number of 26 teams.
  - Each team has the same number of members.
  - No two runners cross the finish line at the same time – i.e. there are no ties.
At the end of the race we can write the results as a string of characters indicating the order in which runners crossed the finish line.
For example: ZZAZAA
We can see there were two teams: A and Z. Team A’s runners finished in 3rd, 5th and 6th place. Team Z’s runners finished in 1st, 2nd and 4th place.
Scoring the race:
Each runner is assigned a score equal to their finishing place. In the example above team Z’s runners achieved scores of 1, 2 and 4. Team A’s runners scores were 3, 5, and 6 respectively.
The team’s score is the sum of the members score divided by the number of people on the team. So team A’s score is (3+5+6)/3 = 14/3=4.66 and team Z’s score is (1+2+4)/3=7/3=2.33
The Problem
Write a program to score races as described above.
Input
Your program will ask the user to input a string of uppercase characters indicating the outcome of a race.
Output
Your program will output:
  - The number of teams.
  - The number of runners on a team.
  - The names of the teams – in alphabetical order - together with the team score.
  - The name and score of the winning team.
So for the example above the program will print: There are 2 teams.
Each team has 3 runners.
Team Score
A 4.66 Z 2.33
The winning team is team Z with a score of 2.33.
Your program should loop asking for input processing the data until the user enters “done”.
Your program should detect the error condition where teams do not have the same number of runners. In that case it should print an error message, and resume by requesting the next input.
