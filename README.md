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

____________________________________________________________________________________________________________________________

HW #9: Modify the Eight Queens program (1 dimensional array – no goto version) so that it prints out a chessboard with some “fancy” representation of a queen in the appropriate positions.
1. Augment that code by adding two additional “box”es, wq which represents a picture of a queen placed in a “white” square, and bq, representing a picture of a queens placed in a “black” square.
2. After the code that fills the array board[8][8] with the addresses of bb and wb, insert code to change eight entries in that array to reflect the positions of eight queens on the board. You will get these positions from a one dimensional array q[8] representing a solution to the eight queens problem. The change that you make in these eight places is to replace the pointer in board for one representing either a wq, or bq, as appropriate for that position. You know the eight positions because, given q[i], i represents the column and q[i] represents the row. You can tell whether its black or white by looking at the row and column indexes of its position on the board.

____________________________________________________________________________________________________________________________

HW #10: Implementing Numerical Integration Using Function Pointers
Inside a loop we sum up the area of rectangles with a small base (say .0001) and height f(x) for each x between a and b in increments of .0001.
When the loop terminates, we return the value of the sum.
The purpose of this assignment is to see (and implement) a very simple application of function pointers.

____________________________________________________________________________________________________________________________

HW #11: Stable Marriage Using Backtracking
You have n men and n woman, and their preference rankings of each other, and you need to match them up so that the total matching is “stable.”
The preference rankings:
You are given 2 n X n arrays, mp (men’s preference) which gives the men’s ranking of the
women, and wp (women’s preference) which gives the women’s ranking of the men.
So mp[i][j] gives man i's ranking of woman j and likewise for the women’s ranking of the men in
wp.
For example in the following tables we have n=3 and the women and men are “named” 0, 1 or 2 and the raking are in the range 0 = highest, 1 second highest and 2 lowest.
int mp[3][3]={0,2,1, 0,2,1,
1,2,0};
int wp[3][3]={2,1,0, 0,1,2,
2,0,1};
So man 1 assigns woman 2 the rank of 1 (i.e. second highest) and prefers woman 0 the best.
What is a stable matching?
A matching is stable if there are no “instabilities.” Say the match assigns m1 to w1 and m2 to w2. An instability is the situation where there is a mutual greater preference for the other person’s partner than for one’s own. For example m1 would prefer w2 to w1 and likewise w2 prefers m1 to m2.
How to do it:
Use the same approach that we used for the one dimensional eight queens problem. In the array q, q[i] is the woman assigned to man i.
The main program stays the same, besides the limits on the loops. All that needs to change is the ok function. Is could look something like this:
bool ok(int q[], int col) {
col indicates the new man and q[col] the new woman proposed to be added to the match.
We need to do 2 tests:
1. If the new woman has already been assigned to some man then return false
2. Check the new pair (new man, new woman) against each existing pair consisting of (current man, current woman) to see if the new pair would make the match unstable. So
a. if the current man prefers the new woman to his partner and
b. if the new woman prefers the current man to her partner
i. this is unstable, so return false
c. if the new man prefers the current woman to his partner and d. if the current woman prefers the new man to her partner
i. This is unstable, so return false
e. if there are no instabilities introduced with any of the existing (i.e. “current”)
 }
couples, so we return true.
____________________________________________________________________________________________________________________________

HW #12: Solve for the 8 Queens problem using 8 for-loops a.k.a. Brute Force
____________________________________________________________________________________________________________________________

HW #13: By the “n queens problem” we mean the problem of placing n queens on an nXn “chessboard” in such a way that no queen can capture any other on the next move. In class we solved the “8 queens” problem.
Write a function that inputs an integer n and returns the number of solutions to the “n queens” problem. Your function should use the one dimensional representation for the board, the algorithm we discussed in class, and no gotos.
Test your function with a main program that prompts the user for an integer n. The main program then calls the function n times, once for each number from 1 – n, and then prints the number of solutions to each of these problems, one on a line.
For example, if you enter n=5 your program should output:
1. There are _____ solutions to the 1 queens problem. 2. There are _____ solutions to the 2 queens problem. 3. There are _____ solutions to the 3 queens problem. 4. There are _____ solutions to the 4 queens problem. 5. There are _____ solutions to the 5 queens problem.
Now, since each time through the loop you will need an array q of a different length, you will need to allocate the array off of the heap
____________________________________________________________________________________________________________________________

HW #14: Using the algorithm discussed in class, write an iterative program to solve the Towers of Hanoi problem.
The problem:
You are given three towers a, b, and c. We start with n rings on tower a and we need to transfer them to tower b subject to the following restrictions:
1. We can only move one ring at a time, and
2. We may never put a larger numbered ring on top of a smaller numbered one.
There are always 3 towers. Your program will prompt the user for the number of rings.
Here is the algorithm.
Definition: A ring is "available" if it is on the top of one of the towers.
Definition: The "candidate" is the smallest available ring that has not been moved on the most recent move. The first candidate is ring 1.
The Algorithm:
1. Find the candidate.
2. Move the candidate (right or left, depending if the number of rings is odd or even) to the closest tower on which it can be placed. Move "around the circle" if necessary.
3. If not done, go back to step 1.
The output should be a set of "commands" of the following form: "Move ring x from tower y to tower z" for each move.
In addition, your program should take 2n-1 moves for any n.

____________________________________________________________________________________________________________________________

Hw #15: Redo using recursion
Using the recursive eight queens as a model, redo
the cross problem using recursion the stable marriage problem
____________________________________________________________________________________________________________________________

HW #16: Write a program that inputs two integers n and k, where n>=k. Your program should calculate the number of different ways that k bishops could be placed on an nXn chessboard.
Structure your program using the backtracking scheme that we have used for the eight queens problem. 
____________________________________________________________________________________________________________________________

HW #17: Shortest Path Problems
1. Modify the code in the handout to include memoization. Modify it additionally so that it prints the actual shortest path as well as its cost. The path should be output as the sequence of rows to choose, going from left to right on the original cost array.
2. Many dynamic programming problems may be solved quite simply from the “bottom up.” Write a program to solve the shortest path problem using a bottom up approach. The path should be output as the sequence of rows to choose, going from left to right on the original cost array.
____________________________________________________________________________________________________________________________

HW #18: Complete the Rat class
Starting with the Rat class (see Handouts) do the following:
1. Add the following operators to the class: operator-()
operator*() operator/()
2. Make sure Rats are reduced to lowest terms. So if a Rat is 2/4 it should be reduced to 1⁄2.
3. If a Rat represents an “improper fraction” (i.e. numerator >denominator) print the Rat as a “mixed number.” So 6/4 will be printed as 1 1⁄2.
____________________________________________________________________________________________________________________________
HW #19: This assignment involves computing continued fractions, and contains three parts. The general form of a continued fraction is:
  where a0 is an integer, all other ai are positive integers, and n is a non-negative integer. We can
 specify a continued fraction by an array of integers containing the values a0 ... an.
 1. Write a function that takes an array of integers as specified above (and ending with a -1) and
 returns the value of the fraction as a double.
 
2. Write a function that takes an array of integers as specified above (and ending with a -1). Your
function will represent the value of the continued fraction as a “regular” fraction, p/q, in lowest
terms. We are looking for the result of doing the fractional arithmetic and keeping everything in
integers as we work our way through. The function returns a 2-element integer array, v, with
v[0]=p and v[1]=q.
 3. Write recursive functions that, given the above representation of a continued fraction, returns
  p and q such that p/q represent the value of the continued fraction as a “regular” fraction in
 lowest terms, as in question 2 above.

____________________________________________________________________________________________________________________________

HW #20: You did it! You got a coveted NSA (National Security Agency) internship because of your exceptional performance in CS211! But as you enter the office your supervisor frantically runs up to you and says that NSA needs you to solve a problem quickly.
She tells you that an international criminal mastermind had been captured with n identical paper copies of a secret password (written as string of ones and zeros) that he was about to distribute to his lieutenants. But just as he was cornered by the police, he managed to rip each copy into two pieces and throw the ripped up papers out of the window. The police managed to retrieve all the papers, but the problem is that the papers were not necessarily ripped up in the same place.
Your task
Your job is to take the papers and write a program to figure out what the original sequence was.
If you can do it within the next hour, you will save the world.
You’re not quite sure how this will save the world, or why a time limit of an hour is specified. Out of earshot of the supervisor, the other programmers tell you that your supervisor made up the whole story to get you to solve the problem as quickly as possible. What really happened was that someone in the office pulled a prank on senior management, and changed the code on the lock of the executive bathroom. The sequence on the torn papers is the new code to the bathroom door ...
Whatever the truth is, you still need to solve the problem. If you do it, you will be a hero; if you don’t, well, your internship and recommendation might be on the line.
The input
Here are the torn papers: 011
0111
01110
111 0111 10111 Caveat
Your supervisor told you that (just in case it happens again) your program should work for any number of torn papers conforming to the story above. Go figure.
