#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "expense.h"
#include<vector>
#include<string>
#include<unordered_map>
class ExpenseManager {
  // This class will manage a collection of Expense objects
  // It will include methods to add, remove, and display expenses
  // as well as any other necessary functionality.
  vector<Expense> expense;
  public:
    void addExpense();
    void displayAllExpense() const;
    void deleteExpenseById();
    void searchByCategory();
    void updateExpenseById();
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    bool isDuplicateId(int id) const;
    void sortByAmount() const;
    void sortByDate() const;
    void showMonthlySummary() const;
};
#endif