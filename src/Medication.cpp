#include "Medication.h"
#include <iostream>
#include <iomanip>

Medication::Medication(std::string name, float price, int qty, Date mfg, Date exp)
    : name(name), unitPrice(price), quantity(qty), manufactureDate(mfg), expiryDate(exp) {}

void Medication::display() const {
    std::cout << std::setw(15) << name
              << " | Price: " << std::setw(6) << unitPrice
              << " | Qty: " << std::setw(4) << quantity << "\n";
    std::cout << "  MFG: " << manufactureDate.day << "/" << manufactureDate.month << "/" << manufactureDate.year;
    std::cout << " | EXP: " << expiryDate.day << "/" << expiryDate.month << "/" << expiryDate.year << "\n";
}

std::string Medication::getName() const { return name; }
int Medication::getQuantity() const { return quantity; }
float Medication::getTotalValue() const { return quantity * unitPrice; }

bool Medication::isExpired(const Date& today) const {
    return expiryDate.isBefore(today);
}

void Medication::sell(int qty) {
    if (qty > quantity) {
        std::cerr << "Not enough in stock!\n";
    } else {
        quantity -= qty;
    }
}

void Medication::restock(int qty) {
    if (qty > 0) quantity += qty;
}

bool Date::isBefore(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}