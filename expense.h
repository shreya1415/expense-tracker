#ifndef EXPENSE_H
#define EXPENSE_H

#include<iostream>
using namespace std;

#include<vector>
#include<algorithm> //for find_if
#include<string>


class Expense{
  int id;
  double amount;
  string category;
  string description;
  string date;
/*

can constructors be public?

Yes, constructors must be public if you want to create objects outside the class.
If they're private, you won't be able to do Expense e; or Expense(…) from outside — only from inside the class or a friend.

*/
public:
  Expense();
  Expense(int id, double amount, string category, string description, string date);
  Expense(const Expense& other);

  void input();
  void display() const;

  friend void printExpense(const Expense& e); //difference between this and display method?

  int getId() const;
  double getAmount() const;
  string getCategory() const;
  string getDescription() const;
  string getDate() const;

  void setAmount(double u_amount);
  void setCategory(string u_category);
  void setDescription(string u_description);
  void setDate(string u_date);
    
};
#endif
