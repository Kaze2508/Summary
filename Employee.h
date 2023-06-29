#pragma once
#include <iostream>
#include <vector>

class Employee 
{
protected:
    std::string employeeId;
    std::string fullName;
    int age;
    std::string phoneNumber;
    std::string email;
    double baseSalary;

public:
    Employee(std::string employeeId, std::string fullName, int age, std::string phoneNumber, std::string email, double baseSalary);
    virtual double calculateSalary()=0;
    void displayDetails();
    void inputEmployees(std::vector<Employee*>& employees);
    void displayEmployees(std::vector<Employee*>& employees);
    double calculateAverageSalary(std::vector<Employee*>& employees);
    void listEmployeesBelowAverageSalary(std::vector<Employee*>& employees);
    void findEmployeesWithMinimumSalary(std::vector<Employee*>& employees);
};