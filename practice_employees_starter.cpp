// PRACTICE: Employee hierarchy (based on the "Additional UML Example" slide)
//
//   EmployeePerson   (base)
//     - fullName, departmentCode, birthday : string
//     - annualSalary : double
//     + SetData(name, dept, birthday, salary)
//     + PrintInfo()                <- make this VIRTUAL
//
//   EmployeeManager  is-a EmployeePerson
//     - numManaged : int
//     + EmployeeManager(int nManaged)
//     + GetNumManaged()
//     + PrintInfo()                <- override: print base info + number managed
//
//   EmployeeStaff    is-a EmployeePerson
//     - managerName : string
//     + EmployeeStaff(string mgrName)
//     + GetManagerName()
//     + PrintInfo()                <- override: print base info + manager's name
//
// TASKS
//  1. Finish the three classes below (look for TODO).
//  2. In each derived PrintInfo(), call EmployeePerson::PrintInfo() first.
//  3. In main(), put one manager and two staff into a vector<EmployeePerson*>
//     and print everyone with ONE loop.
//  4. Remove "virtual" from the base PrintInfo(). What changes? Why?
//  5. CHALLENGE: add a pure virtual function  double ComputeBonus() const = 0;
//     Managers get 10% of salary, staff get 5%. What happens if you now try
//     to create a plain EmployeePerson object?

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EmployeePerson {
public:
   virtual ~EmployeePerson() {}

   void SetData(string name, string dept, string bday, double salary) {
      // TODO: store the four values
   }

   virtual void PrintInfo() const {
      // TODO: print fullName, departmentCode, birthday, annualSalary
   }

protected:
   string fullName;
   string departmentCode;
   string birthday;
   double annualSalary = 0.0;
};

class EmployeeManager : public EmployeePerson {
public:
   // TODO: constructor that sets numManaged
   // TODO: GetNumManaged()
   // TODO: PrintInfo() override
private:
   int numManaged = 0;
};

class EmployeeStaff : public EmployeePerson {
public:
   // TODO: constructor that sets managerName
   // TODO: GetManagerName()
   // TODO: PrintInfo() override
private:
   string managerName;
};

int main() {
   // TODO: create the objects, fill a vector<EmployeePerson*>, print in one loop
   return 0;
}
