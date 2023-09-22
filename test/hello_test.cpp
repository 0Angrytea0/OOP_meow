#include <gtest/gtest.h>
#include <string>
#include "lib.h" 
using namespace std;



TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange 
  string first = "asda";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0; 

  // act
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 2);
}

TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  // arrange 
  string first = "aa e i o y u";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0;

  // act 
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 7);
}

TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  // arrange 
  string first = "aeaeae ia is su s";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0; 

  // act
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 10);
}

TEST(ExampleOfStandartUsageTest4, BasicAssertions) {
  // arrange 
  string first = "a";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0; 

  // act
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest5, BasicAssertions) {
  // arrange 
  string first = "a   asdf ef   efa";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0; 

  // act
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 5);
}

TEST(ExampleOfStandartUsageTest6, BasicAssertions) {
  // arrange 
  string first = " ";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0; 

  // act
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 0);
}

TEST(ExampleOfStandartUsageTest7, BasicAssertions) {
  // arrange 
  string first = " a ";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0; 

  // act
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest8, BasicAssertions) {
  // arrange 
  string first = "       o";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0; 

  // act
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 1);
}

TEST(ExampleOfStandartUsageTest9, BasicAssertions) {
  // arrange 
  string first = "                  ";
  char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
  int k = 0; 

  // act 
  int result = kolvo(k, first, vowel);
  
  // assert
  EXPECT_EQ(result, 0);
}
