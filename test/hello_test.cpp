#include <gtest/gtest.h>
#include <string>
#include "lib.h" 
using namespace std;



TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  string first = "asda";

  int result = quantity_of_vowels(first);
  
  EXPECT_EQ(result, 2);
}

TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  string second = "aa e i o y u";

  int result = quantity_of_vowels(second);

  EXPECT_EQ(result, 7);
}

TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  string third = "aeaeae ia is su s";

  int result = quantity_of_vowels(third);

  EXPECT_EQ(result, 10);
}

TEST(ExampleOfStandartUsageTest4, BasicAssertions) {
  // arrange 
  string fouth = "a";

  int result = quantity_of_vowels(fouth);
  
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest5, BasicAssertions) {
  // arrange 
  string fifth = "a   asdf ef   efa";
 
  int result = quantity_of_vowels(fifth);
  
  EXPECT_EQ(result, 5);
}

TEST(ExampleOfStandartUsageTest6, BasicAssertions) {
  string sixth = " ";

  int result = quantity_of_vowels(sixth);
  
  EXPECT_EQ(result, 0);
}

TEST(ExampleOfStandartUsageTest7, BasicAssertions) {
  string seventh = " a ";

  int result = quantity_of_vowels(seventh);
  
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest8, BasicAssertions) {
  string eighth = "       o";

  int result = quantity_of_vowels(eighth);
  
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest9, BasicAssertions) {
  string nineth = "                  ";

  int result = quantity_of_vowels(nineth);
  
  EXPECT_EQ(result, 0);
}

TEST(ExampleOfStandartUsageTest10, BasicAssertions) {
  string tenth = "1234";

  int result = quantity_of_vowels(tenth);
  
  EXPECT_EQ(result, 0);
}
