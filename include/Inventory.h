#pragma once
#include "Medication.h"
#include <list>

class Inventory {
private:
    std::list<Medication> meds;

public:
    void addMedication(const Medication& m);
    void listMedications() const;
    void sellMedication(const std::string& name, int qty);
    void restockMedication(const std::string& name, int qty);
    void listExpired(const Date& today) const;
    void totalValue() const;
};