// Copyright 2025 UNN-CS
#include <cstdint>
#include <vector>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }

  bool isPrime = true;

  for (uint64_t i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      isPrime = false;
      break;
    }
  }

  return isPrime;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;

  uint64_t count = 0;
  uint64_t num = 2;

  while (count < n) {
    if (checkPrime(num)) {
      count++;
      if (count == n) {
        return num;
      }
    }
    num++;
  }

  return num;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;

  while (!checkPrime(num)) {
    num++;
  }

  return num;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;

  std::vector<bool> sieve(hbound, true);
  sieve[0] = sieve[1] = false;

  for (uint64_t i = 2; i * i < hbound; i++) {
    if (sieve[i]) {
      for (uint64_t j = i * i; j < hbound; j += i) {
        sieve[j] = false;
      }
    }
  }

  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (sieve[i]) {
      sum += i;
    }
  }

  return sum;
}
