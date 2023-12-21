//DoubleScripted Class Modified from Fig10.10 & Fig10.11 (Array Class)
#pragma once
#include <iostream>
#include <memory> // for unique_ptr and make_unique
#include <vector>

class DoubleScriptedArray {
   friend std::ostream& operator<<(std::ostream&, const DoubleScriptedArray&);
   friend std::istream& operator>>(std::istream&, DoubleScriptedArray&);
public:

   explicit DoubleScriptedArray(int = 1, int = 1); // default constructor  
   DoubleScriptedArray(const DoubleScriptedArray&); // copy constructor
   size_t getRowSize() const; //Return amount of rows
   size_t getColumnSize() const; //Return amount of columns
   size_t getSize() const; //Return combined size

   const DoubleScriptedArray& operator=(const DoubleScriptedArray&); // assignment operator
   bool operator==(const DoubleScriptedArray&) const; // equality operator   

   // inequality operator; returns opposite of == operator     
   bool operator!=(const DoubleScriptedArray& right) const {
      return !(*this == right); // invokes Array::operator==
   }

   // subscript operator for non-const objects returns modifiable lvalue
   int& operator()(int, int);

   // subscript operator for const objects returns rvalue
   int operator()(int, int) const;

private:
   size_t rowSize; // How many rows there are
   size_t columnSize; // How many columns there are
   size_t size; //Actual size
   std::unique_ptr<int[]> ptr; // smart pointer
};
