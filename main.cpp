#include "ExpenseManager.h"
#include<iostream>
int main(){
  ExpenseManager manager;
  int choice;
  string filename="Expense_Tracker.csv";
  do{
    cout<<"\n-----Personal expense tracker-----"<<endl;
    cout<<"1. Add Expense"<<endl;
    cout<<"2. Display Expense"<<endl;
    cout<<"3. Delete Expense by ID"<<endl;
    cout<<"4. Search Expense by Category"<<endl;
    cout<<"5. Sort by Amount "<<endl;
    cout<<"6. Sort by Date"<<endl;
    cout<<"7. Update Expense by ID" << endl;
    cout<<"8. Show monthly summary"<< endl;
    cout<<"9. Save to file"<<endl;
    cout<<"10. Load from file"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"Enter you choice"<<endl;
    cin>>choice;
    switch(choice){
      case 1:manager.addExpense();
            break;
      case 2:manager.displayAllExpense();
            break;
      case 3:manager.deleteExpenseById();
            break;
      case 4:manager.searchByCategory();
            break;
      case 5:manager.sortByAmount();
            break;
      case 6:manager.sortByDate();
            break;
      case 7:manager.updateExpenseById();
            break;
      case 8:manager.showMonthlySummary();
            break;
      case 9:manager.saveToFile(filename);
            break;
      case 10:manager.loadFromFile(filename);
            break;
      case 0:cout<<"Exiting..."<<endl;
            break;
      default:cout<<"Invalid choice. Try again"<<endl;

    }

  }while(choice!=0);
  return 0;
}