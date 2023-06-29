#include "Employee.h"
#include "Programmer.h"
#include "Tester.h"
#include <string>

Employee::Employee(std::string employeeId, std::string fullName, int age, std::string phoneNumber, std::string email, double baseSalary)
    : employeeId(employeeId), fullName(fullName), age(age), phoneNumber(phoneNumber), email(email), baseSalary(baseSalary) {}

void Employee::displayDetails() 
{
    std::cout << "Employee ID: " << employeeId << std::endl;
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Email: " << email << std::endl;
}

void Employee::inputEmployees(std::vector<Employee*>& employees) 
{
    int numEmployees;
    std::cout << "Enter the number of employees: ";
    std::cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++) {
        std::string employeeId, fullName, phoneNumber, email;
        int age;
        double baseSalary;

        std::cout << "\nEnter details for Employee #" << i + 1 << ":" << std::endl;
        std::cout << "Employee ID: ";
        std::cin >> employeeId;
        std::cout << "Full Name: ";
        std::cin.ignore();
        getline(std::cin, fullName);
        std::cout << "Age: ";
        std::cin >> age;
        std::cout << "Phone Number: ";
        std::cin.ignore();
        getline(std::cin, phoneNumber);
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << "Base Salary: ";
        std::cin >> baseSalary;

        char employeeType;
        std::cout << "Employee Type (P for Programmer, T for Tester): ";
        std::cin >> employeeType;

        if (employeeType == 'P') 
        {
            int overtimeHours;
            std::cout << "Overtime Hours: ";
            std::cin >> overtimeHours;
            employees.push_back(new Programmer(employeeId, fullName, age, phoneNumber, email, baseSalary, overtimeHours));
        }
        else if (employeeType == 'T') 
        {
            int bugsDetected;
            std::cout << "Bugs Detected: ";
            std::cin >> bugsDetected;
            employees.push_back(new Tester(employeeId, fullName, age, phoneNumber, email, baseSalary, bugsDetected));
        }
    }
}

void Employee::displayEmployees(std::vector<Employee*>& employees) 
{
    for (Employee* employee : employees) 
    {
        employee->displayDetails();
        std::cout << "Salary: " << employee->calculateSalary() << std::endl;
        std::cout << std::endl;
    }
}

double Employee::calculateAverageSalary(std::vector<Employee*>& employees) 
{
    double totalSalary = 0.0;
    for (Employee* employee : employees) 
    {
        totalSalary += employee->calculateSalary();
    }
    return totalSalary / employees.size();
}

void Employee::listEmployeesBelowAverageSalary(std::vector<Employee*>& employees) 
{
    double averageSalary = calculateAverageSalary(employees);
    std::cout << "Employees with salary below average:" << std::endl;
    for (Employee* employee : employees) 
    {
        if (employee->calculateSalary() < averageSalary) 
        {
            employee->displayDetails();
            std::cout << "Salary: " << employee->calculateSalary() << std::endl;
            std::cout << std::endl;
        }
    }
}

void Employee::findEmployeesWithMinimumSalary(std::vector<Employee*>& employees) 
{
    double minSalary;
    std::cout << "Enter the minimum salary: ";
    std::cin >> minSalary;

    std::cout << "Employees with salary above or equal to " << minSalary << ":" << std::endl;
    for (Employee* employee : employees) 
    {
        if (employee->calculateSalary() >= minSalary) 
        {
            employee->displayDetails();
            std::cout << "Salary: " << employee->calculateSalary() << std::endl;
            std::cout << std::endl;
        }
    }
}