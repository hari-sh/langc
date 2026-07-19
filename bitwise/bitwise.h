#ifndef BITWISE_H
#define BITWISE_H

#include <stdint.h>

int isEven(uint32_t n);
int isPowerOfTwo(uint32_t n);
int isBitSet(uint32_t n, uint32_t pos);
int isSingleBitDifferent(uint32_t a, uint32_t b);

uint32_t getBit(uint32_t n, uint32_t pos);
uint32_t setBit(uint32_t n, uint32_t pos);
uint32_t clearBit(uint32_t n, uint32_t pos);
uint32_t toggleBit(uint32_t n, uint32_t pos);
uint32_t extractBits(uint32_t n, uint32_t start, uint32_t count);
uint32_t replaceBits(uint32_t n, uint32_t value, uint32_t start, uint32_t count);
uint32_t countSetBits(uint32_t n);
uint32_t countSetBitsWithoutLoop(uint32_t n);
uint32_t countLeadingZeros(uint32_t n);
uint32_t countTrailingZeros(uint32_t n);
uint32_t getHighestSetBit(uint32_t n);
uint32_t findUniqueNumber(const uint32_t *nums, uint32_t size);
uint32_t findMissingNumber(const uint32_t *nums, uint32_t size);
uint32_t findDuplicateNumber(const uint32_t *nums, uint32_t size);
uint32_t findUniqueAmongTriplicates(const uint32_t *nums, uint32_t size);
uint32_t maxXorPair(const uint32_t *nums, uint32_t size);
uint32_t maxXorSubarray(const uint32_t *nums, uint32_t size);
uint32_t getRightmostSetBit(uint32_t n);
uint32_t swapOddEvenBits(uint32_t n);
uint32_t reverseBits(uint32_t n);
uint32_t reverseBitsWithoutLoop(uint32_t n);
uint32_t reverseBytes(uint32_t n);
uint32_t swapNibbles(uint32_t n);
uint32_t clearRightmostSetBit(uint32_t n);
uint32_t setRightmostUnsetBit(uint32_t n);
uint32_t clearTrailingOnes(uint32_t n);
uint32_t addWithoutPlus(uint32_t a, uint32_t b);
uint32_t multiplyWithoutMultiply(uint32_t a, uint32_t b);
uint32_t divideWithoutDivide(uint32_t a, uint32_t b);
uint32_t rotateLeft(uint32_t n, uint32_t pos);
uint32_t rotateRight(uint32_t n, uint32_t pos);
uint32_t nextPowerOfTwo(uint32_t n);
uint32_t nextSameSetBits(uint32_t n);
uint32_t previousSameSetBits(uint32_t n);
uint32_t xorFromOneToN(uint32_t n);
uint32_t binaryToGray(uint32_t n);
uint32_t grayToBinary(uint32_t n);

int hasEvenParity(uint32_t n);
int hasAlternatingBits(uint32_t n);
int isSubset(uint32_t a, uint32_t b);
int isPowerOfFour(uint32_t n);
int isBitPalindrome(uint32_t n);
uint32_t hammingDistance(uint32_t a, uint32_t b);
uint32_t bitwiseAndRange(uint32_t left, uint32_t right);
uint32_t reverseBitsInRange(uint32_t n, uint32_t start, uint32_t count);
uint64_t countSetBitsFromOneToN(uint32_t n);
void findTwoUniqueNumbers(const uint32_t *nums, uint32_t size, uint32_t *a, uint32_t *b);
void findTwoMissingNumbers(const uint32_t *nums, uint32_t size, uint32_t *a, uint32_t *b);

#endif
