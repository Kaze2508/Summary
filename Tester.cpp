#include "Tester.h"

Tester::Tester(std::string employeeId, std::string fullName, int age, std::string phoneNumber, std::string email, double baseSalary, int bugsDetected)
    : Employee(employeeId, fullName, age, phoneNumber, email, baseSalary), bugsDetected(bugsDetected) {}

double Tester::calculateSalary()
{
    return baseSalary + bugsDetected * 50000;
}