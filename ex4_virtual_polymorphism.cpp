// Example 4: Runtime polymorphism with virtual functions
// A base class pointer can point to a derived class object.
// With "virtual", the OBJECT decides which function runs (at runtime).
// Without "virtual", the POINTER TYPE decides (at compile time).

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
   Animal(string animalName) { name = animalName; }
   virtual ~Animal() {}       // good habit: virtual destructor in a base class

   // Try removing the word "virtual" below, recompile, and compare the output!
   virtual string Speak() const { return "..."; }

   // NOT virtual, on purpose, to show the difference
   string Kind() const { return "some animal"; }

   string GetName() const { return name; }

protected:
   string name;
};

class Dog : public Animal {
public:
   Dog(string dogName) : Animal(dogName) {}
   string Speak() const override { return "Woof!"; }
   string Kind() const { return "dog"; }        // hides, but is not virtual
};

class Cat : public Animal {
public:
   Cat(string catName) : Animal(catName) {}
   string Speak() const override { return "Meow!"; }
   string Kind() const { return "cat"; }
};

int main() {
   // 1) Derived-to-base pointer conversion: no cast needed
   Dog rex("Rex");
   Animal* animalPtr = &rex;

   cout << "Through an Animal* pointing to a Dog:" << endl;
   cout << "  Speak() -> " << animalPtr->Speak() << "   (virtual: uses Dog's)" << endl;
   cout << "  Kind()  -> " << animalPtr->Kind()  << "   (not virtual: uses Animal's)" << endl;

   // 2) The real payoff: one loop handles every kind of animal
   vector<Animal*> shelter;
   shelter.push_back(new Dog("Buddy"));
   shelter.push_back(new Cat("Whiskers"));
   shelter.push_back(new Animal("Mystery"));
   shelter.push_back(new Cat("Luna"));

   cout << "\nRoll call at the shelter:" << endl;
   for (size_t i = 0; i < shelter.size(); ++i) {
      cout << "  " << shelter.at(i)->GetName() << " says "
           << shelter.at(i)->Speak() << endl;
   }

   // Clean up the heap objects
   for (size_t i = 0; i < shelter.size(); ++i) {
      delete shelter.at(i);
   }

   return 0;
}
