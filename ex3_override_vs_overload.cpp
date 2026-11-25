// Example 3: Overriding vs. overloading
// Overriding  = SAME signature in base and derived class (child replaces parent's version)
// Overloading = SAME name, DIFFERENT parameters (compile-time polymorphism)

#include <iostream>
#include <string>
using namespace std;

class Business {
public:
   void SetName(string busName)         { name = busName; }
   void SetAddress(string busAddress)   { address = busAddress; }

   string GetDescription() const {
      return name + " -- " + address;
   }

protected:
   string name;
   string address;
};

class Restaurant : public Business {
public:
   void SetRating(int userRating) { rating = userRating; }

   // OVERRIDE: identical declaration to Business::GetDescription()
   string GetDescription() const {
      // Reuse the parent's version, then add to it
      return Business::GetDescription() + "\n  Rating: " + to_string(rating) + "/5";
   }

private:
   int rating = 0;
};

// OVERLOADING: same function name, different parameter lists.
// The compiler picks which one to call by looking at the arguments.
void PrintValue(int x)              { cout << "int: " << x << endl; }
void PrintValue(double x)           { cout << "double: " << x << endl; }
void PrintValue(string x)           { cout << "string: " << x << endl; }
void PrintValue(string x, int times) {
   for (int i = 0; i < times; ++i) { cout << x << " "; }
   cout << endl;
}

int main() {
   Business someBusiness;
   someBusiness.SetName("ACME");
   someBusiness.SetAddress("4 Main St");

   Restaurant favoritePlace;
   favoritePlace.SetName("Friends Cafe");
   favoritePlace.SetAddress("500 2nd Ave");
   favoritePlace.SetRating(5);

   cout << "Overriding:" << endl;
   cout << someBusiness.GetDescription() << endl;   // Business version
   cout << favoritePlace.GetDescription() << endl;  // Restaurant version

   cout << "\nOverloading (decided at compile time):" << endl;
   PrintValue(42);
   PrintValue(3.14);
   PrintValue(string("hello"));
   PrintValue(string("Hi!"), 3);

   return 0;
}
