#pragma once
#include <iostream>
#include "Employee.h"

class Programmer : public Employee 
{
private:
    int overtimeHours;

public:
    Programmer(std::string employeeId, std::string fullName, int age, std::string phoneNumber, std::string email, double baseSalary, int overtimeHours);
    double calculateSalary() override;
};