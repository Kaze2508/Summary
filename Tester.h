#pragma once
#include "Employee.h"
#include <iostream>

class Tester : public Employee 
{
private:
    int bugsDetected;

public:
    Tester(std::string employeeId, std::string fullName, int age, std::string phoneNumber, std::string email, double baseSalary, int bugsDetected);
    double calculateSalary() override;
};