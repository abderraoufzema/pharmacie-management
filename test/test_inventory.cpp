#include "Inventory.h"
#include <cassert>
#include <iostream>

void testMedicationBasics() {
    Date fab = {1, 1, 2023};
    Date exp = {1, 1, 2025};
    Medication med("Paracetamol", 10.5f, 20, fab, exp);

    assert(med.getName() == "Paracetamol");
    assert(med.getQuantity() == 20);
    assert(med.getTotalValue() == 210.0f);

    med.sell(5);
    assert(med.getQuantity() == 15);

    med.restock(10);
    assert(med.getQuantity() == 25);

    std::cout << "testMedicationBasics passed.\n";
}

void testInventoryOperations() {
    Inventory inv;
    Date fab = {1, 1, 2022};
    Date exp = {1, 1, 2024};
    Medication med("Ibuprofen", 15.0f, 10, fab, exp);
    inv.addMedication(med);

    inv.sellMedication("Ibuprofen", 3);
    inv.restockMedication("Ibuprofen", 5);

    std::cout << "testInventoryOperations passed.\n";
}

void testExpirationLogic() {
    Date fab = {1, 1, 2020};
    Date exp = {1, 1, 2022};
    Medication expiredMed("Aspirin", 5.0f, 5, fab, exp);

    Date today = {1, 1, 2023};
    assert(expiredMed.isExpired(today));

    Date earlier = {1, 1, 2021};
    assert(!expiredMed.isExpired(earlier));

    std::cout << "testExpirationLogic passed.\n";
}

int main() {
    testMedicationBasics();
    testInventoryOperations();
    testExpirationLogic();
    std::cout << "All tests passed!\n";
    return 0;
}