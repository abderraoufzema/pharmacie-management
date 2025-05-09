#include "Inventory.h"
#include <iostream>

int main() {
    Inventory inv;
    int choice;

    do {
        std::cout << "\n1. Add Medication\n2. View All\n3. Sell\n4. Expired\n5. Total Value\n6. Restock\n0. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            float price;
            int qty, d1, m1, y1, d2, m2, y2;
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Price: "; std::cin >> price;
            std::cout << "Qty: "; std::cin >> qty;
            std::cout << "MFG (d m y): "; std::cin >> d1 >> m1 >> y1;
            std::cout << "EXP (d m y): "; std::cin >> d2 >> m2 >> y2;

            Date fab{d1, m1, y1};
            Date exp{d2, m2, y2};
            Medication m(name, price, qty, fab, exp);
            inv.addMedication(m);
        }
        else if (choice == 2) {
            inv.listMedications();
        }
        else if (choice == 3) {
            std::string name;
            int qty;
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Qty to sell: "; std::cin >> qty;
            inv.sellMedication(name, qty);
        }
        else if (choice == 4) {
            Date today;
            std::cout << "Enter today's date (d m y): ";
            std::cin >> today.day >> today.month >> today.year;
            inv.listExpired(today);
        }
        else if (choice == 5) {
            inv.totalValue();
        }
        else if (choice == 6) {
            std::string name;
            int qty;
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Qty to add: "; std::cin >> qty;
            inv.restockMedication(name, qty);
        }
    } while (choice != 0);

    return 0;
}