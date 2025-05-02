// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include <vector>
#include "alg.h"

// Тесты для checkPrime
TEST(CheckPrimeTest, SimpleNumbers) {
  std::vector<uint64_t> nums = {2, 3, 5, 7, 11};
  for (auto i : nums) {
    EXPECT_TRUE(checkPrime(i));
  }
}

TEST(CheckPrimeTest, NonPrimeNumbers) {
  std::vector<uint64_t> nums = {4, 6, 8, 9};
  for (auto i : nums) {
    EXPECT_FALSE(checkPrime(i));
  }
}

TEST(CheckPrimeTest, EdgeCases) {
  std::vector<uint64_t> nums = {0, 1};
  for (auto i : nums) {
    EXPECT_FALSE(checkPrime(i));
  }
}

TEST(CheckPrimeTest, LargeNumbers) {
  std::vector<uint64_t> nums = {997, 1009};
  for (auto i : nums) {
    EXPECT_TRUE(checkPrime(i));
  }
}

// Тесты для nPrime
TEST(NPrimeTest, FirstFivePrimes) {
  std::vector<uint64_t> nums = {2, 3, 5, 7};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(nPrime(i + 1), nums[i]);
  }
}

TEST(NPrimeTest, ZeroCase) {
  std::vector<uint64_t> nums = {0};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(nPrime(i), nums[i]);
  }
}

TEST(NPrimeTest, LargerNumbers) {
  std::vector<uint64_t> nums = {10, 15};
  std::vector<uint64_t> expected = {29, 47};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(nPrime(nums[i]), expected[i]);
  }
}

// Тесты для nextPrime
TEST(NextPrimeTest, SimpleSequence) {
  std::vector<uint64_t> nums = {2, 3, 5, 7};
  std::vector<uint64_t> expected = {3, 5, 7, 11};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(nextPrime(nums[i]), expected[i]);
  }
}

TEST(NextPrimeTest, NonPrimeInput) {
  std::vector<uint64_t> nums = {4, 6, 8, 9};
  std::vector<uint64_t> expected = {5, 7, 11, 11};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(nextPrime(nums[i]), expected[i]);
  }
}

TEST(NextPrimeTest, LargerGaps) {
  std::vector<uint64_t> nums = {28, 95};
  std::vector<uint64_t> expected = {29, 97};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(nextPrime(nums[i]), expected[i]);
  }
}

// Тесты для sumPrime
TEST(SumPrimeTest, SmallBounds) {
  std::vector<uint64_t> nums = {5, 10};
  std::vector<uint64_t> expected = {5, 17};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(sumPrime(nums[i]), expected[i]);
  }
}

TEST(SumPrimeTest, MediumBounds) {
  std::vector<uint64_t> nums = {20, 30};
  std::vector<uint64_t> expected = {77, 129};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(sumPrime(nums[i]), expected[i]);
  }
}

TEST(SumPrimeTest, EdgeCases) {
  std::vector<uint64_t> nums = {2, 1, 0};
  std::vector<uint64_t> expected = {0, 0, 0};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(sumPrime(nums[i]), expected[i]);
  }
}

TEST(SumPrimeTest, SpecificBounds) {
  std::vector<uint64_t> nums = {11, 12};
  std::vector<uint64_t> expected = {17, 28};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(sumPrime(nums[i]), expected[i]);
  }
}

TEST(SumPrimeTest, LargerNumbers) {
  std::vector<uint64_t> nums = {50, 100};
  std::vector<uint64_t> expected = {328, 1060};
  for (size_t i = 0; i < nums.size(); i++) {
    EXPECT_EQ(sumPrime(nums[i]), expected[i]);
  }
}

TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}
TEST(st1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}
