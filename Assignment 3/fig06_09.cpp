// Fig. 6.9: fig06_09.cpp
// Craps simulation.
#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
using namespace std;

//Converted this file into a namespace so I can just use it without too much modification - MP
namespace fig06_09{
   //Modified this function to take a pointer - MP
   unsigned int rollDice(int* rollPtr); // rolls dice, calculates and displays sum
   //Modified main to return true/false and take a pointer so I can pass it to rollDice - MP
   bool main(int* rollPtr) {
      // scoped enumeration with constants that represent the game status 
      enum class Status {CONTINUE, WON, LOST}; // all caps in constants

      unsigned int myPoint{0}; // point if no win or loss on first roll
      Status gameStatus; // can be CONTINUE, WON or LOST
      //Roll dice, and pass the address of the pointer so it can increment in the main file - MP
      unsigned int sumOfDice{rollDice(&*rollPtr)}; // first roll of the dice

      // determine game status and point (if needed) based on first roll
      switch (sumOfDice) {
         case 7: // win with 7 on first roll
         case 11: // win with 11 on first roll           
            gameStatus = Status::WON;
            break;
         case 2: // lose with 2 on first roll
         case 3: // lose with 3 on first roll
         case 12: // lose with 12 on first roll             
            gameStatus = Status::LOST;
            break;
         default: // did not win or lose, so remember point
            gameStatus = Status::CONTINUE; // game is not over
            myPoint = sumOfDice; // remember the point
            //cout << "Point is " << myPoint << endl;
            break; // optional at end of switch  
      }

      // while game is not complete
      while (Status::CONTINUE == gameStatus) { // not WON or LOST
         sumOfDice = rollDice(&*rollPtr); // roll dice again

         // determine game status
         if (sumOfDice == myPoint) { // win by making point
            gameStatus = Status::WON;
         }
         else {
            if (sumOfDice == 7) { // lose by rolling 7 before point
               gameStatus = Status::LOST;
            }
         }
      }

      // display won or lost message
      if (Status::WON == gameStatus) {
         //cout << "Player wins" << endl;
         //If the game is won, return true - MP
         return true;
      }
      else {
         //cout << "Player loses" << endl;
         //Otherwise, return false - MP
         return false;
      }
   }

   // roll dice, calculate sum and display results, as well as increment the pointer per 1 - MP
   unsigned int rollDice(int* rollPtr) {
      int die1{1 + rand() % 6}; // first die roll
      int die2{1 + rand() % 6}; // second die roll
      int sum{die1 + die2}; // compute sum of die values

      // display results of this roll
      //cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
      *rollPtr += 1;
      return sum;
   }
}



/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
