#include<gtest/gtest.h>
#include "expense.h"

TEST(ExpenseTest, Getters){
  Expense e(1, 280.05, "Food", "Pasta", "16/08/2025"); //tests constructor and getter

  EXPECT_EQ(e.getId(),1);
  EXPECT_DOUBLE_EQ(e.getAmount(),280.05);
  EXPECT_EQ(e.getCategory(),"Food");
  EXPECT_EQ(e.getDescription(),"Pasta");
  EXPECT_EQ(e.getDate(),"16/08/2025");

  EXPECT_NE(e.getId(),2);
  EXPECT_NE(e.getAmount(),280.04);
  EXPECT_NE(e.getCategory(),"Foods");
  EXPECT_NE(e.getDescription(),"Chips");
  EXPECT_NE(e.getDate(),"16/08/2024");

}
TEST(ExpenseTest, Setters){ //tests setters
  Expense e;
  e.setAmount(25.96);
  e.setCategory("Rent");
  e.setDescription("pg");
  e.setDate("14/01/2000");

  EXPECT_DOUBLE_EQ(e.getAmount(),25.96);
  EXPECT_EQ(e.getCategory(),"Rent");
  EXPECT_EQ(e.getDescription(),"pg");
  EXPECT_EQ(e.getDate(),"14/01/2000");

  EXPECT_NE(e.getAmount(),25.00);
  EXPECT_NE(e.getCategory(),"rent");
  EXPECT_NE(e.getDescription(),"house");
  EXPECT_NE(e.getDate(),"15/01/2000");
}