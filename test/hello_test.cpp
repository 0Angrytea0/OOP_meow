#include <gtest/gtest.h>
#include <string>
#include "lib.h" 
using namespace std;



TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange 
  string first = "asda";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0; 

  // act
  int result = quantity_of_vowels(quantity, first, vowels);
  
  // assert
  EXPECT_EQ(result, 2);
}

TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  // arrange 
  string second = "aa e i o y u";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0;

  // act 
  int result = quantity_of_vowels(quantity, second, vowels);
  
  // assert
  EXPECT_EQ(result, 7);
}

TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  // arrange 
  string third = "aeaeae ia is su s";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0; 

  // act
  int result = quantity_of_vowels(quantity, third, vowels);
  
  // assert
  EXPECT_EQ(result, 10);
}

TEST(ExampleOfStandartUsageTest4, BasicAssertions) {
  // arrange 
  string fouth = "a";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0; 

  // act
  int result = quantity_of_vowels(quantity, fouth, vowels);
  
  // assert
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest5, BasicAssertions) {
  // arrange 
  string fifth = "a   asdf ef   efa";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0; 

  // act
  int result = quantity_of_vowels(quantity, fifth, vowels);
  
  // assert
  EXPECT_EQ(result, 5);
}

TEST(ExampleOfStandartUsageTest6, BasicAssertions) {
  // arrange 
  string sixth = " ";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0; 

  // act
  int result = quantity_of_vowels(quantity, sixth, vowels);
  
  // assert
  EXPECT_EQ(result, 0);
}

TEST(ExampleOfStandartUsageTest7, BasicAssertions) {
  // arrange 
  string seventh = " a ";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0; 

  // act
  int result = quantity_of_vowels(quantity, seventh, vowels);
  
  // assert
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest8, BasicAssertions) {
  // arrange 
  string eighth = "       o";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0; 

  // act
  int result = quantity_of_vowels(quantity, eighth, vowels);
  
  // assert
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest9, BasicAssertions) {
  // arrange 
  string nineth = "                  ";
  char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int quantity = 0; 

  // act 
  int result = quantity_of_vowels(quantity, nineth, vowels);
  
  // assert
  EXPECT_EQ(result, 0);
}
