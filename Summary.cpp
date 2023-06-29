#include <iostream>
#include "Employee.h"
#include "Programmer.h"
#include "Tester.h"

int main(int argc, char* argv[])
{
    std::vector<Employee*> employees;

    employees.push_back(new Programmer("P001", "John Doe", 30, "123456789", "john@example.com", 5000000, 10));
    employees.push_back(new Tester("T001", "Jane Smith", 25, "987654321", "jane@example.com", 4000000, 5));

    // Cleanup
    for (Employee* employee : employees) {
        delete employee;
    }

    return 0;
}