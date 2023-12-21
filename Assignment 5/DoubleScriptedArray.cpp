//DoubleScripted Class Modified from Fig10.10 & Fig10.11 (Array Class)
// Array class member- and friend-function definitions.
#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "DoubleScriptedArray.h" // DoubleScriptedArray class definition
using namespace std;

//My formatting in this file and most likely all others will probably be all over the place. Blame Visual Studio for auto-changing my formatting as I go along. I can't get it to play nice with tabs for some reason

// default constructor for class Array (default size 10)
DoubleScriptedArray::DoubleScriptedArray(int rowAmount, int columnAmount) :
   rowSize{(rowAmount > 0 ? static_cast<size_t>(rowAmount) :
      throw invalid_argument{"DoubleScriptedArray row size must be greater than 0"})},
   columnSize{(columnAmount > 0 ? static_cast<size_t>(columnAmount) :
      throw invalid_argument{"DoubleScriptedArray column size must be greater than 0"})},
   //This line, if I understand what I did right, will only make size equal to row * col if row & col are greater than one. Otherwise, it just adds together
   size{rowSize > 1 && columnSize > 1 ? rowSize * columnSize : rowSize + columnSize},
   ptr{make_unique<int[]>(size)} {};

// copy constructor for class Array;
// must receive a reference to an Array
DoubleScriptedArray::DoubleScriptedArray(const DoubleScriptedArray& arrayToCopy)
   : size{arrayToCopy.size}, ptr{make_unique<int[]>(size)} {
   for (int i{0}; i < size; ++i) {
      ptr[i] = arrayToCopy.ptr[i];
   }
}

//Return total size of the array
size_t DoubleScriptedArray::getSize() const {
   return size; //Total number of elements in Array
}

//Return amount of rows in the array
size_t DoubleScriptedArray::getRowSize() const {
    return rowSize; //Number of rows in the array
}

//Return amount of columns in the array
size_t DoubleScriptedArray::getColumnSize() const {
    return columnSize; //Number of columns in the array
}

//This is unchanged
// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
const DoubleScriptedArray& DoubleScriptedArray::operator=(const DoubleScriptedArray& right) {
   if (&right != this) { // avoid self-assignment
      // for Arrays of different sizes, deallocate original
      // left-side Array, then allocate new left-side Array
      if (size != right.size) {
         size = right.size; // resize this object
         ptr = make_unique<int[]>(size); // create space for copy
      }

      for (size_t i{0}; i < size; ++i) {
         ptr[i] = right.ptr[i]; // copy array into object
      }
   }

   return *this; // enables x = y = z, for example
}

//Unchanged
// determine if two Arrays are equal and
// return true, otherwise return false
bool DoubleScriptedArray::operator==(const DoubleScriptedArray& right) const {
   if (size != right.size) {
      return false; // arrays of different number of elements
   }

   for (size_t i{0}; i < size; ++i) {
      if (ptr[i] != right.ptr[i]) {
         return false; // Array contents are not equal
      }
   }

   return true; // Arrays are equal
}

//Here I added the extra checking for both row and column out of bounds, and then made it return the correct element
// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int& DoubleScriptedArray::operator()(int rowScript, int columnScript) {
   // check for subscript out-of-range error
   if (rowScript < 0 || rowScript >= rowSize) {
      throw out_of_range{"Row out of range"};
   }
   if (columnScript < 0 || columnScript >= columnSize) {
      throw out_of_range{"Column out of range"};
   }

   return ptr[columnSize * rowScript + columnScript];
   
}

//Here I added the extra checking for both row and column out of bounds, and then made it return the correct element
// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int DoubleScriptedArray::operator()(int rowScript, int columnScript) const {
   // check for subscript out-of-range error
   if (rowScript < 0 || rowScript >= rowSize) {
      throw out_of_range{"Row out of range"};
   }
   if (columnScript < 0 || columnScript >= columnSize) {
      throw out_of_range{"Column out of range"};
   }

   return ptr[columnSize * rowScript + columnScript];

}

//Here I've added prompts and made it look pretty so you know where you're assigning a specific value in the array
// overloaded input operator for class Array;
// inputs values for entire Array
istream& operator>>(istream& input, DoubleScriptedArray& a) {

    //Set flags for the row/column number
    int rowFlag{ 1 };
    int colFlag{ 1 };

    for (size_t i{0}; i < a.size; ++i) {
        //Print prompt
        cout << "Enter Value for Row #" << rowFlag << ", Column #" << colFlag << ": ";
        //Add one to the column number
        colFlag += 1;
        //If you hit the amount of columns, increment row flag by one and reset column flag
        if ((i + 1) % a.columnSize == 0) {
            rowFlag += 1;
            colFlag = 1;
        }

        input >> a.ptr[i];
    }

   return input; // enables cin >> x >> y;
}

//Here I've changed the output to hopefully look somewhat like a table
// overloaded output operator for class Array 
ostream& operator<<(ostream& output, const DoubleScriptedArray& a) {
   // output private ptr-based array 

    //Print the contents of the array in table format. It won't look pretty with bigger numbers, but I really don't want to go messing around with iomanip stuff right now
    for (size_t i{0}; i < a.size; i++) {
       output << " | " << a.ptr[i] << " | ";
       if ((i + 1) % a.columnSize == 0) {
            output << endl;
       }
           
   }

   output << endl;
   return output; // enables cout << x << y;
}