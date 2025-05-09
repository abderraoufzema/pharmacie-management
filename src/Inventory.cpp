#include "Inventory.h"
#include <iostream>

void Inventory::addMedication(const Medication& m) {
    meds.push_back(m);
}

void Inventory::listMedications() const {
    for (const auto& m : meds) m.display();
}

void Inventory::sellMedication(const std::string& name, int qty) {
    for (auto& m : meds) {
        if (m.getName() == name) {
            m.sell(qty);
            return;
        }
    }
    std::cerr << "Medication not found!\n";
}

void Inventory::restockMedication(const std::string& name, int qty) {
    for (auto& m : meds) {
        if (m.getName() == name) {
            m.restock(qty);
            return;
        }
    }
    std::cerr << "Medication not found for restock!\n";
}

void Inventory::listExpired(const Date& today) const {
    for (const auto& m : meds) {
        if (m.isExpired(today)) m.display();
    }
}

void Inventory::totalValue() const {
    float total = 0.0f;
    for (const auto& m : meds) total += m.getTotalValue();
    std::cout << "Total stock value: " << total << " DZD\n";
}