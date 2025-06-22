#include "expense.h"
#include <iostream>
#include <regex>
#include "ExpenseManager.h"
using namespace std;

Expense::Expense(): id(0), amount(0.0), category(""), description(""), date(""){} //what is the purpose of this constructor? why these dafault values?

Expense::Expense(int id, double amount, string category, string description, string date)
    : id(id), amount(amount), category(category), description(description), date(date){}

Expense::Expense(const Expense& other){    // explicit Copy constructor - member-wise copy
  id = other.id;
  amount = other.amount;
  category = other.category;
  description = other.description;
  date = other.date;
}
bool isValidDateFormat(const string& date){
  regex pattern(R"(^\d{2}/\d{2}/\d{4}$)");
  return regex_match(date, pattern);
}
void Expense::input(){
  ExpenseManager manager;
  bool exists = true;
  do{
  cout << "Enter ID: "; //check if this can be auto- generated   , make sure it is unique
  // maybe use a static variable to keep track of the last ID used
  // or use a database to store the expenses and generate unique IDs
  cin >> id;
  exists = manager.isDuplicateId(id);
  if(exists){
    cout << "ID exists. \n"<<endl;
  }
   
  }while(exists);

  bool negative = true;
  do{
    cout << "Enter amount: ";
    cin >> amount;
    if(amount < 0){
      cout << "Enter positive value" << endl;
    }
    else negative = false;

  }while(negative);

  cout << "Enter category: ";
  cin >> category;
  cout << "Enter description: ";
  cin.ignore();
  getline(cin, description);

  do{
    cout << "Enter date (DD/MM/YYYY):"; //see if you can use a date library, calendar
    cin >> date;
    if(!isValidDateFormat(date)){
      cout << "Invalid date format. Try again." << endl;
    }

  }while(!isValidDateFormat(date));
}

void Expense::display() const{
  cout << id << " || " << amount << " || " << category << " || " << description << " || " << date << endl;
}

void printExpense(const Expense& e) { //friend function to access private members
  cout << e.id << " || " << e.amount << " || " << e.category << " || " << e.description << " || " << e.date << endl;
}// learn this 

int Expense::getId()const{
  return id;
}
double Expense::getAmount() const{
  return amount;
}

string Expense::getCategory() const{
  return category;
}
string Expense::getDescription() const{
  return description;
}
string Expense::getDate() const{
  return date;
}

void Expense::setAmount(double u_amount){
  amount = u_amount;
}

void Expense::setCategory(string u_category){
  category = u_category;
}

void Expense::setDescription(string u_description){
  description = u_description;
}

void Expense::setDate(string u_date){
  date = u_date;
}


