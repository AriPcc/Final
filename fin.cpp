/******************************************************************************
# Author:            Ari P.
# Assignment:        Final Exam
# Date:              June 12, 2025
# Description:       This program will get the user's walking goal for the
                     week, and then their miles walked each day. It'll
                     determine whether they met their goal, and how far above
                     or below it they were.
# Input:             goal (int), miles (int)
# Output:            totalMiles (int), difference (int)
# Sources:           Final exam specifications, zyBooks reference
#*****************************************************************************/

#include <iostream>
using namespace std;

// Declare core functions, which are defined after main()
void welcome();
void getInput(int& goal);
int calcTotal();
void goodbye();

int main() {
   // Declare variables for input and output
   int goal = 0;
   int totalMiles = 0;
   int difference = 0;

   // Print a welcome message
   welcome();
   cout << endl;

   // Read the user's goal
   getInput(goal);
   // Make sure they entered a valid amount
   if (cin.fail() || goal <= 0) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "No miles were tracked this week." << endl;
      goodbye();
      return 0;
   }

   // Get the number of miles walked this week
   totalMiles = calcTotal();
   difference = abs(goal - totalMiles);
   cout << endl;

   // Display the results
   cout << "You walked " << totalMiles << " mile";
   if (totalMiles != 1) {
      cout << "s";
   }
   cout << " this week." << endl;

   if (totalMiles < goal) {
      cout << "You didn't meet your goal! You needed to walk " << difference << " more mile";
      if (difference > 1) {
         cout << "s";
      }
      cout << "." << endl;
   }
   else if (totalMiles == goal) {
      cout << "You met your goal exactly!" << endl;
   }
   else if (totalMiles > goal) {
      cout << "You met your goal, and surpassed it by " << difference << " mile";
      if (difference > 1) {
         cout << "s";
      }
      cout << "!" << endl;
   }
   cout << endl;

   // Print a goodbye message
   goodbye();
   return 0;
}

// Define core functions
// Name:    welcome()
// Desc:    This function prints a welcome message
// Input:   None
// Output:  Text
// Return:  void
void welcome() {
   cout << "Welcome to the Big Stepper Tracker. Please be entirely honest." << endl;
}

// Name:    getInput
// Desc:    This function gets the number of miles the user wants to walk in a
//          week.
// Input:   goal (int)
// Output:  Prompt
// Return:  void
void getInput(int& goal) {
   cout << "How many miles would you like to walk this week? ";
   cin >> goal;
}

// Name:    calcTotal()
// Desc:    This function gets the number of miles walked in a week, one day at
//          a time.
// Input:   miles (int)
// Output:  Prompt
// Return:  totalMiles (int)
int calcTotal() {
   int miles = 0;
   int totalMiles = 0;
   for (int i = 1; i <= 7; i++) {
      cout << "How many miles did you walk on ";
      switch (i) {
         case 1:
            cout << "Monday? ";
            break;
         case 2:
            cout << "Tuesday? ";
            break;
         case 3:
            cout << "Wednesday? ";
            break;
         case 4:
            cout << "Thursday? ";
            break;
         case 5:
            cout << "Friday? ";
            break;
         case 6:
            cout << "Saturday? ";
            break;
         case 7:
            cout << "Sunday? ";
            break;
      }
      cin >> miles;
      if (cin.fail() || miles < 0) {
         cin.clear();
         cin.ignore(100, '\n');
         cout << "You can't walk negative miles!" << endl;
         i -= 1;
         continue;
      }
      totalMiles += miles;
   }
   return totalMiles;
}

// Name:    goodbye()
// Desc:    This function prints a goodbye message
// Input:   None
// Output:  Text
// Return:  void
void goodbye() {
   cout << "Thanks for using the Big Stepper Tracker. Keep on stepping." << endl;
}
