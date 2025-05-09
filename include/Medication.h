#pragma once
#include <string>

struct Date {
    int day, month, year;
    bool isBefore(const Date& other) const;
};

class Medication {
private:
    std::string name;
    float unitPrice;
    int quantity;
    Date manufactureDate;
    Date expiryDate;

public:
    Medication(std::string name, float price, int qty, Date mfg, Date exp);
    void display() const;
    std::string getName() const;
    int getQuantity() const;
    float getTotalValue() const;
    bool isExpired(const Date& today) const;
    void sell(int qty);
    void restock(int qty);
};