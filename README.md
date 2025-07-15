Personal Expense Tracker (C++)
------------------------------
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)


A command-line application to track your daily expenses. Add, update, delete and view expenses with date-based, expense-based sorting and monthly summaries. The code is modular, tested and built using C++, STL and Google Test.


Features
--------

1. Add, view, update, delete expense records
2. Save and load data from CSV file
3. Validate inputs(unique ID, non-negative amount, date format)
4. Sort expenses by amount or date
5. Show monthly summary of total expenses
6. Unit tested with Google Test
7. Modular structure with Makefile 


Technologies used
-----------------

1. C++
2. STL ('vector', 'unordered map','regex')
3. Google Test for unit testing
4. Makefile for compilation


Getting started
---------------
Compile and run
---------------

make

./ExpenseTracker


Run Unit Tests
--------------

g++ test_expense.cpp expense.cpp ExpenseManager.cpp -lgtest -lgtest_main -pthread -o test_expense ./test_expense


Author
------

Shreya N Bhat

Email: shreya.n1000@gmail.com
