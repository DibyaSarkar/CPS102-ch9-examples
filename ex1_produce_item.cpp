// Example 1: Base class vs. derived class
// GenericItem (base) and ProduceItem (derived) — follows zyBooks Figure 9.1.1
// Topics: inheritance syntax, protected vs. private, calling a base class
//         constructor, calling a base class function with ClassName::

#include <iostream>
#include <string>
using namespace std;

class GenericItem {
public:
   GenericItem() {                                  // default constructor
      itemName = "none";
      itemQuantity = 0;
      cout << "  [GenericItem default constructor]" << endl;
   }

   GenericItem(string name, int quantity) {         // alternate constructor
      itemName = name;
      itemQuantity = quantity;
      cout << "  [GenericItem(name, quantity) constructor]" << endl;
   }

   void SetName(string newName) { itemName = newName; }
   void SetQuantity(int newQty) { itemQuantity = newQty; }

   void PrintItem() const {
      cout << itemName << " " << itemQuantity << endl;
   }

protected:
   string itemName;        // derived classes CAN use this directly

private:
   int itemQuantity;       // derived classes can NOT touch this directly;
                           // it still exists inside every ProduceItem object
};

// "public" here = public members stay public, protected stay protected
class ProduceItem : public GenericItem {
public:
   ProduceItem() {
      // GenericItem's default constructor already ran automatically
      expirationDate = "unknown";
   }

   // Call the ALTERNATE base constructor with an initializer list
   ProduceItem(string name, int quantity, string expDate)
      : GenericItem(name, quantity) {
      expirationDate = expDate;
   }

   void SetExpiration(string newDate) { expirationDate = newDate; }
   string GetExpiration() const { return expirationDate; }

   void PrintProduce() const {
      GenericItem::PrintItem();                        // reuse base class code
      cout << "  (expires " << expirationDate << ")" << endl;

      // itemName is protected -> allowed:
      cout << "  Name via protected member: " << itemName << endl;

      // itemQuantity is private -> uncomment to see the compiler error:
      // cout << itemQuantity << endl;
   }

private:
   string expirationDate;
};

int main() {
   cout << "Creating a GenericItem:" << endl;
   GenericItem miscItem;
   miscItem.SetName("Smith Cereal");
   miscItem.SetQuantity(9);
   miscItem.PrintItem();

   cout << "\nCreating a ProduceItem with the default constructor:" << endl;
   ProduceItem perishItem;
   perishItem.SetName("Apples");          // inherited from GenericItem
   perishItem.SetQuantity(40);            // inherited from GenericItem
   perishItem.SetExpiration("May 5, 2027");
   perishItem.PrintProduce();

   cout << "\nCreating a ProduceItem with the alternate constructor:" << endl;
   ProduceItem banana("Bananas", 12, "Dec 1, 2026");
   banana.PrintProduce();

   return 0;
}
