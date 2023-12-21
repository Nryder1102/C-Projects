// Fig. 10.18: Hugeinteger.cpp 
// HugeInteger member-function and friend-function definitions.
#include <cctype> // isdigit function prototype
#include <array>
#include "Hugeinteger.h" // HugeInteger class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
HugeInteger::HugeInteger(long value) {
   // place digits of argument into array 
   for (int j{digits - 1}; value != 0 && j >= 0; j--) {
      integer[j] = value % 10;
      value /= 10;
   }
}

// conversion constructor that converts a character string 
// representing a large integer into a HugeInteger object
HugeInteger::HugeInteger(const string& number) {
   // place digits of argument into array
   uint64_t length{number.size()};

   for (uint64_t j{digits - length}, k{0}; j < digits; ++j, ++k) {
      if (isdigit(number[k])) { // ensure that character is a digit
         integer[j] = number[k] - '0';
      }
   }
}

// addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::operator+(const HugeInteger& op2) const {
   HugeInteger temp; // temporary result
   int carry = 0;

   for (int i{digits - 1}; i >= 0; i--) {
      temp.integer[i] = integer[i] + op2.integer[i] + carry;

      // determine whether to carry a 1
      if (temp.integer[i] > 9) {
         temp.integer[i] %= 10;  // reduce to 0-9
         carry = 1;
      }else { // no carry 
         carry = 0;
      }
   }

   return temp; // return copy of temporary object
}

HugeInteger HugeInteger::operator-(const HugeInteger& op2) const {
   HugeInteger temp; // temporary result
   int carry = 0;

   for (int i{digits - 1}; i >= 0; i--) {
      if (integer[i] - carry < op2.integer[i]){
			temp.integer[i] = (integer[i] + 10) - op2.integer[i] - carry;
			carry = 1;
		}
		else
		{
			temp.integer[i] = integer[i] - op2.integer[i] - carry;
			carry = 0;
		}
   }

   return temp; // return copy of temporary object
}

// addition operator; HugeInteger + int
HugeInteger HugeInteger::operator+(int op2) const {
   return *this + HugeInteger(op2);
}
// HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator+(const string& op2) const {
   return *this + HugeInteger(op2);
}
HugeInteger HugeInteger::operator-(int op2) const {
   return *this - HugeInteger(op2);
}
HugeInteger HugeInteger::operator-(const string& op2) const {
   return *this - HugeInteger(op2);
}

//Plus Equals
HugeInteger HugeInteger::operator+=(const HugeInteger& op2){
   *this = *this + op2;
   return *this;
}

HugeInteger HugeInteger::operator-=(const HugeInteger& op2){
   *this = *this - op2;
   return *this;
}

bool HugeInteger::operator==(const HugeInteger& op2) const {
   for (int i{digits - 1}; i >= 0; i--) {
      if(integer[i] != op2.integer[i]){
         return false;
      }
   }
   return true;
}

bool HugeInteger::operator<(const HugeInteger& op2 ) const { 
   //Run through every digit
   for (size_t i{0}; i < digits; ++i){ 
      //If it's the same, continue
      if(integer[i] == op2.integer[i]){
         continue; 
      //Else if the integer is bigger, return false
      }else if (integer[i] > op2.integer[i]){
         return false; 
      //If the integer is smaller, return true
      }else{
         return true;
      } 
   } 
   return false; 
}

bool HugeInteger::operator>(const HugeInteger& op2) const {
   //Do it this way so it grabs from the < operator, basically just doing the other operation in reverse
   return op2 < *this;
}


// overloaded output operator
ostream& operator<<(ostream& output, const HugeInteger& num) {
   int i;

   // skip leading zeros
   for (i = 0; (i < HugeInteger::digits) && (0 == num.integer[i]); ++i) {}

   if (i == HugeInteger::digits) {
      output << 0;
   }
   else {
      for (; i < HugeInteger::digits; ++i) {
         output << num.integer[i];
      }
   }

   return output;
}

istream& operator>>(istream& input, HugeInteger& num) {
   long temp;
   input >> temp;
   num = HugeInteger(temp);
   return input;
}

/**************************************************************************
 * (C) Copyright 1992-2017 /by Deitel & Associates, Inc. and               *
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
