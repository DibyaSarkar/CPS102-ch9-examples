class GenericItem {
public:
   void SetName(string newName) { itemName = newName; }
   void SetQuantity(int newQty) { itemQuantity = newQty; }
   void PrintItem() const { cout << itemName << " " << itemQuantity << endl; }
protected:
   string itemName;     // derived classes can use this
private:
   int itemQuantity;    // derived classes cannot
};

class ProduceItem : public GenericItem {
public:
   void SetExpiration(string newDate) { expirationDate = newDate; }
   void PrintProduce() const {
      GenericItem::PrintItem();
      cout << "  Name via protected member: " << itemName << endl;   // OK
      // cout << itemQuantity << endl;                              // ERROR
   }
private:
   string expirationDate;
};
