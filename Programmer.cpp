#include "Programmer.h"

Programmer::Programmer(std::string employeeId, std::string fullName, int age, std::string phoneNumber, std::string email, double baseSalary, int overtimeHours)
    : Employee(employeeId, fullName, age, phoneNumber, email, baseSalary), overtimeHours(overtimeHours) {}

double Programmer::calculateSalary()
{
    return baseSalary + overtimeHours * 200000;
}