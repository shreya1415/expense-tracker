all: ExpenseTracker

ExpenseTracker: main.o expense.o ExpenseManager.o
	g++ main.o expense.o ExpenseManager.o -o ExpenseTracker

main.o: main.cpp expense.h ExpenseManager.h
	g++ -c main.cpp

expense.o: expense.cpp expense.h
	g++ -c expense.cpp

ExpenseManager.o: ExpenseManager.cpp ExpenseManager.h expense.h
	g++ -c ExpenseManager.cpp

clean:
	rm -f *.o ExpenseTracker