// When you create a derived object, C++ first builds the base part. If you say nothing, it calls the base class's default constructor automatically.
// But what if the base class has a better constructor, one that takes a name and a quantity? We call it from the derived constructor using a colon after the parameter list:

// ProduceItem(string name, int quantity, string expDate)
//    : GenericItem(name, quantity) {     // run this base constructor first
//    expirationDate = expDate;           // then set our own member
// }

// Read it as: "to build a ProduceItem, first build its GenericItem part with name and quantity, then do the rest."
// The same idea works for ordinary functions. To call the base version of a function from inside the derived class, put the class name and two colons in front:

// GenericItem::PrintItem();


// Example 2: Order of constructor and destructor calls
// Class C (base) -> Class B (derived from C) -> Class A (derived from B)
// Constructors run top-down (C, B, A); destructors run bottom-up (A, B, C).

#include <iostream>
using namespace std;

class C {
public:
   C()  { cout << "C() constructor" << endl; }
   ~C() { cout << "~C() destructor" << endl; }
};

class B : public C {
public:
   B()  { cout << "B() constructor" << endl; }
   ~B() { cout << "~B() destructor" << endl; }
};

class A : public B {
public:
   A()  { cout << "A() constructor" << endl; }
   ~A() { cout << "~A() destructor" << endl; }
};

int main() {
   cout << "--- Entering block, creating an A object ---" << endl;
   {
      A obj;
      cout << "--- obj is alive; leaving the block now ---" << endl;
   }  // obj goes out of scope here
   cout << "--- Block finished ---" << endl;
   return 0;
}

// Think about it: why must the base part be built FIRST?
// (Hint: the derived constructor might use inherited members.)
