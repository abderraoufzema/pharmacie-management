
# MediStock – C++ Pharmacy Management System

MediStock is a modular, object-oriented console application written in C++ for managing a small pharmacy's medication inventory.

## 🧾 Features

- Add new medications with name, quantity, price, manufacture and expiration dates
- Sell medications and auto-decrement quantity
- Restock medications
- Display current stock and total inventory value
- List expired medications based on a given date
- Menu-based console interface

## 🧪 Testing

Unit tests are written using `assert` in `test/test_inventory.cpp`. They test:

- Medication creation, selling, restocking
- Inventory operations
- Expiration logic

### Run Tests

```bash
g++ src/*.cpp test/test_inventory.cpp -Iinclude -o test_medi
./test_medi
```

You should see:

```
testMedicationBasics passed.
testInventoryOperations passed.
testExpirationLogic passed.
All tests passed!
```

## 🛠 Build & Run

```bash
g++ src/*.cpp -Iinclude -o MediStock
./MediStock
```

Follow the on-screen menu to interact with the system.

## 📁 Project Structure

```
MediStock/
├── include/
│   ├── Medication.h
│   └── Inventory.h
├── src/
│   ├── Medication.cpp
│   ├── Inventory.cpp
│   └── main.cpp
├── test/
│   └── test_inventory.cpp
└── README.md
```

## 📦 How to Upload to GitHub (Git Guide)

### 1. Initialize Git

```bash
git init
```

### 2. Add files

```bash
git add .
```

### 3. Commit with a message

```bash
git commit -m "Initial commit: MediStock pharmacy system"
```

### 4. Create a GitHub repo and add remote

On GitHub, create a new repo called `MediStock` (don’t initialize with README).

Then:

```bash
git remote add origin https://github.com/YOUR_USERNAME/MediStock.git
git branch -M main
git push -u origin main
```

That's it! ✅

## 📄 License

MIT License – free to use, modify, and distribute.

# pharmacie-management

