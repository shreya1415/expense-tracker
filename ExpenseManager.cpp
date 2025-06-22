#include "ExpenseManager.h"
#include<iostream>
#include<fstream>
#include<sstream>
void ExpenseManager::addExpense(){
  Expense e;
  e.input();
  expense.push_back(e);
}

void ExpenseManager::displayAllExpense() const {
  if(expense.empty()){
    cout << "No expense records found." << endl;
    return;                                   //no need to go through the loop if empty.
  }
  for(const auto& e :expense){
    e.display();
  }
}

void ExpenseManager::deleteExpenseById(){ //use of id parameter here?
  int id;
  cout << "Enter the ID of the expense to be deleted: ";
  cin >> id;
    auto it = find_if(expense.begin(),expense.end(), [id](const Expense& e) {
     return e.getId() == id; 
   });
   if(it!=expense.end()){
    expense.erase(it);
    cout << "Expense with ID " << id << " has been deleted." << endl;
   }
   else{
    cout << "Expense with ID " << id << " not found." << endl;
   }


  // for(auto it = expense.begin();it!=expense.end();it++){
  //   if(it-> getId() == id){
  //     expense.erase(it);
  //     cout << "Expense with ID " << id << "has been deleted." << endl;
  //     return;
  //   }
  // }
  // cout << "Expense with ID " << id << " not found." << endl;
  
}
void ExpenseManager::searchByCategory() {
  string category;
  cout << "Enter category to search:";
  cin >> category;



  if(expense.empty()){
    cout << "No expense records found." << endl;
    return; //no need to search if empty
  }
  //predicate function to find the expense by category
  //using lambda function to find the expense by category

  // auto it = find_if(expense.begin(), expense.end(), [category](const Expense& e){   should use this to erase a particular expense
  //   return (e.getCategory()) == (category); // compare()?
  // });
  bool found = false;
  
    for (auto it = expense.begin(); it != expense.end(); ++it) {
      if (it->getCategory() == category){
        it->display();
        found = true;
      }
    }
  

  if(!found){
    cout << "No expense found in category: "<< category <<endl;
  }


}

void ExpenseManager::updateExpenseById() { // use ExpenseManager:: else you cant access expense vector
  string update_field;
  double update_amount;
  string update_category;
  string update_description;
  string update_date;
  int id;
  bool found = false;
  cout << "Enter the ID of the expense to be updated:";
  cin >> id;

  for(auto &e: expense){
    if(e.getId() == id){
      found = true;
      cout << "Enter the field to be updated (amount, category, description, date)";
      cin.ignore();
      getline(cin, update_field);

      //convert to lower case
      transform(update_field.begin(),update_field.end(),update_field.begin(), ::tolower);

      if(update_field == "amount"){
        cout << "Enter the amount to be updated" << endl;
        cin >> update_amount;

        e.setAmount(update_amount);

      }
      else if(update_field == "category"){
        cout << "Enter the category" << endl;
        cin >> update_category;

        e.setCategory(update_category);
      }
      else if(update_field == "description"){
        cout << "Enter the description" << endl;
        cin.ignore();
        getline(cin, update_description);

        e.setDescription(update_description);
      }
      else if(update_field == "date"){ 
        cout << "Enter the date" << endl;
        cin >> update_date;
        
        e.setDate(update_date);

      }
      else{
        cout << "Enter the correct field" << endl;
      }
      
    }
    
      
    
  }
  if(!found){
    cout << "ID not found" << endl;  //some error
  }
  

}

void ExpenseManager::saveToFile(const string& filename) const{  //about the parameters
  ofstream outFile(filename);
  if(!outFile){
    cout << "Error opening the file" << endl;
    return;
  }
  //outFile << "ID,Amount,Category,Description,Date" <<endl; //error was because of this
  for(auto &e:expense){
  outFile << e.getId() << "," << e.getAmount() << "," << e.getCategory() << "," << e.getDescription() << "," << e.getDate() << endl;
  }

  outFile.close();

}

void ExpenseManager::loadFromFile(const string& filename){ // error here as well. solved. 
  ifstream inFile(filename);
  if(!inFile){
    cout << "Error opening the file" << endl;
    return;
  }
  expense.clear();
  string line;
  while(getline(inFile,line)){
    stringstream s(line);                             //read about this
    string id_str, amount_str, category, description, date;
    getline(s,id_str,','); 
    getline(s,amount_str,',');
    getline(s,category,',');
    getline(s,description,',');
    getline(s,date,',');

    if(id_str.empty() || amount_str.empty()) continue;
    int id = stoi(id_str);
    double amount = stod(amount_str);

    Expense e(id,amount,category,description,date);
    expense.push_back(e);
  }
  inFile.close();
}
bool ExpenseManager::isDuplicateId(int id) const{
  for(const auto& e: expense){
    if(e.getId() == id){
      return true;
    }
  }
  return false;
}
int dateToInt(const string &date){
  int day = stoi(date.substr(0,2));
  int month = stoi(date.substr(3,2));
  int year = stoi(date.substr(6,4));
  return ((year*10000) + (month*100) + day);
}

void ExpenseManager::sortByAmount() const{
  vector<Expense>sorted_amount;
  sorted_amount = expense;
  sort(sorted_amount.begin(), sorted_amount.end(), [](Expense a,Expense b){
    return a.getAmount()<b.getAmount();
  });
  for(auto &a: sorted_amount){
    a.display();
  }
}
void ExpenseManager::sortByDate() const{
  vector<Expense>sorted_date;
  sorted_date = expense;
  sort(sorted_date.begin(),sorted_date.end(),[](const Expense &a, const Expense &b){
      return dateToInt(a.getDate())<dateToInt(b.getDate());
  });
  for(auto &d:sorted_date){
    d.display();
  }
}
void ExpenseManager::showMonthlySummary()const{
  unordered_map<string,double> monthlyTotals;
  for(const auto &d:expense){
    monthlyTotals[d.getDate().substr(3,7)]+=d.getAmount(); // go through the working again
  }
  cout<<"\n----Monthly Summary---"<<endl;                 // Add visual summary using bar graph style if possible
  for(const auto &total:monthlyTotals){
    cout<<total.first<<" : "<<total.second<<endl;
  }
}