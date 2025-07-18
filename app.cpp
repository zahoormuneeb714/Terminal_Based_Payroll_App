#include <iostream>
#include <string>
using namespace std;

//! Employee :)
class Employee
{
protected:
    string name;
    double taxRate;

public:
    Employee(string n, double tr)
    {
        cout << endl
             << "Employee::Overloaded Consturctor" << endl;
        name = n;
        taxRate = tr;
    }
    string getName() const
    {
        return name;
    }
    virtual double calcSalary() = 0; //! PURE VITRUAL FUNCTION
    virtual ~Employee()
    {
        cout << endl
             << "Employee::~Destructor" << endl;
    }
};

//! Salaried Employee :)
class SalariedEmployee : public Employee
{
private:
    double salary;

public:
    SalariedEmployee(string n, double tr, double s) : Employee(n, tr)
    {
        cout << endl
             << "SalariedEmployee:: Overlaoded Constructor" << endl;
        salary = s;
    }
    double calcSalary()
    {
        double tax = (salary / 100) * taxRate;
        double netSalary = salary - tax;
        return netSalary;
    }
    ~SalariedEmployee()
    {
        cout << endl
             << "SalariedEmployee::Destructor" << endl;
    }
};

//! Hourly Employee :)
class HourlyEmployee : public Employee
{
private:
    int hours;
    double hourRate;

public:
    HourlyEmployee(string n, double tr, int h, double hr) : Employee(n, tr)
    {
        cout << endl
             << "HourlyEmployee::Consturctor" << endl;
        hours = h;
        hourRate = hr;
    }
    double calcSalary()
    {
        int grossSalary = hours * hourRate;
        int tax = (grossSalary / 100) * taxRate;
        int netSalary = grossSalary - tax;
        return netSalary;
    }
    ~HourlyEmployee()
    {
        cout << endl
             << "HourlyEmployee::Desturctor" << endl;
    }
};

//! Commisoned Employee :)
class CommEmployee : public Employee
{
private:
    double sales;
    double commRate;

public:
    CommEmployee(string n, double tr, double s, double cr) : Employee(n, tr)
    {
        cout << endl
             << "CommEmployee::Consturtor" << endl;
        sales = s;
        commRate = cr;
    }
    double calcSalary()
    {
        double grossSalary = (sales / 100) * commRate;
        double tax = (grossSalary / 100) * taxRate;
        double netSalary = grossSalary - tax;
        return netSalary;
    }
    ~CommEmployee()
    {
        cout << endl
             << "CommEmployee::Destructor" << endl;
    }
};

//! GENERATE PAYROLL :)

void generatePayroll(Employee *emp[], int size)
{
    cout << "\nName\tNetSalary";
    for (int i = 0; i < size; i++)
    {
        cout << endl
             << emp[i]->getName() << "\t"
             << emp[i]->calcSalary();
    }
}

//! MAIN PROGRAM :)
int main()
{
    Employee *emp[10];
    emp[0] = new SalariedEmployee("Muneeb", 10, 30000);
    emp[1] = new HourlyEmployee("Mehmood", 10, 150, 200);
    emp[2] = new CommEmployee("Alia", 10, 200000, 15);

    generatePayroll(emp, 10);
    return 0;
}
