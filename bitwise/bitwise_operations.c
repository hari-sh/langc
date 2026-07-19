#include <stdint.h>
#include <stdio.h>

int isEven(uint32_t n) {
    return (n & 1) == 0;
}

uint32_t getBit(uint32_t n, uint32_t pos) {
    if (pos >= 32) {
        return 0;
    }

    return (n >> pos) & 1;
}

uint32_t setBit(uint32_t n, uint32_t pos) {
    if (pos >= 32) {
        return n;
    }

    return n | ((uint32_t)1 << pos);
}

uint32_t clearBit(uint32_t n, uint32_t pos) {
    if (pos >= 32) {
        return n;
    }

    return n & ~((uint32_t)1 << pos);
}

uint32_t toggleBit(uint32_t n, uint32_t pos) {
    if (pos >= 32) {
        return n;
    }

    return n ^ ((uint32_t)1 << pos);
}

int isBitSet(uint32_t n, uint32_t pos) {
    return getBit(n, pos) != 0;
}

int isPowerOfTwo(uint32_t n) {
    return n != 0 && (n & (n - 1)) == 0;
}

uint32_t countSetBits(uint32_t n) {
    uint32_t count = 0;

    while (n != 0) {
        n &= n - 1;
        ++count;
    }

    return count;
}

uint32_t findUniqueNumber(const uint32_t *nums, uint32_t size) {
    uint32_t result = 0;
    uint32_t i;

    for (i = 0; i < size; ++i) {
        result ^= nums[i];
    }

    return result;
}

uint32_t getRightmostSetBit(uint32_t n) {
    return n & (~n + 1);
}

int isSingleBitDifferent(uint32_t a, uint32_t b) {
    return isPowerOfTwo(a ^ b);
}

void findTwoUniqueNumbers(const uint32_t *nums, uint32_t size, uint32_t *a, uint32_t *b) {
    uint32_t bit;
    uint32_t i;

    *a = 0;
    *b = 0;

    for (i = 0; i < size; ++i) {
        *a ^= nums[i];
    }

    bit = getRightmostSetBit(*a);
    *a = 0;

    for (i = 0; i < size; ++i) {
        if ((nums[i] & bit) != 0) {
            *a ^= nums[i];
        } else {
            *b ^= nums[i];
        }
    }
}

uint32_t swapOddEvenBits(uint32_t n) {
    const uint32_t evenMask = 0x55555555;
    const uint32_t oddMask = 0xAAAAAAAA;

    return ((n & evenMask) << 1) | ((n & oddMask) >> 1);
}

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    uint32_t i;

    for (i = 0; i < 32; ++i) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }

    return result;
}

uint32_t reverseBitsWithoutLoop(uint32_t n) {
    const uint32_t mask1 = 0x55555555;
    const uint32_t mask2 = 0x33333333;
    const uint32_t mask4 = 0x0F0F0F0F;
    const uint32_t mask8 = 0x00FF00FF;

    n = ((n >> 1) & mask1) | ((n & mask1) << 1);
    n = ((n >> 2) & mask2) | ((n & mask2) << 2);
    n = ((n >> 4) & mask4) | ((n & mask4) << 4);
    n = ((n >> 8) & mask8) | ((n & mask8) << 8);

    return (n >> 16) | (n << 16);
}

uint32_t clearRightmostSetBit(uint32_t n) {
    return n & (n - 1);
}

uint32_t addWithoutPlus(uint32_t a, uint32_t b) {
    uint32_t carry;

    while (b != 0) {
        carry = (a & b) << 1;
        a ^= b;
        b = carry;
    }

    return a;
}

uint32_t rotateLeft(uint32_t n, uint32_t pos) {
    pos %= 32;

    if (pos == 0) {
        return n;
    }

    return (n << pos) | (n >> (32 - pos));
}

uint32_t rotateRight(uint32_t n, uint32_t pos) {
    pos %= 32;

    if (pos == 0) {
        return n;
    }

    return (n >> pos) | (n << (32 - pos));
}

uint32_t nextPowerOfTwo(uint32_t n) {
    if (n == 0 || isPowerOfTwo(n)) {
        return n == 0 ? 1 : n;
    }

    if (n > 0x80000000) {
        return 0;
    }

    --n;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return n + 1;
}

uint32_t countLeadingZeros(uint32_t n) {
    uint32_t count = 0;
    uint32_t i;

    for (i = 0; i < 32; ++i) {
        if (isBitSet(n, 31 - i)) {
            return count;
        }

        ++count;
    }

    return count;
}

int main(void) {
    const uint32_t nums[] = {0x4, 1, 0x2, 1, 0x2};
    const uint32_t twoNums[] = {1, 0x2, 1, 0x3, 0x2, 0x5};
    const uint32_t n = 0x2A;
    uint32_t a;
    uint32_t b;

    printf("Is %d even? %s\n", 0x2A, isEven(0x2A) ? "yes" : "no");
    printf("Bit at 3: %u\n", (unsigned int)getBit(n, 3));
    printf("Bit 0 set: %u\n", (unsigned int)setBit(n, 0));
    printf("Bit 1 cleared: %u\n", (unsigned int)clearBit(n, 1));
    printf("Bit 1 toggled: %u\n", (unsigned int)toggleBit(n, 1));
    printf("Is bit 3 set? %s\n", isBitSet(n, 3) ? "yes" : "no");
    printf("Is %u a power of two? %s\n", (unsigned int)n, isPowerOfTwo(n) ? "yes" : "no");
    printf("Set bits in %u: %u\n", (unsigned int)n, (unsigned int)countSetBits(n));
    printf("Unique number: %u\n", (unsigned int)findUniqueNumber(nums, 5));
    printf("Rightmost set bit: %u\n", (unsigned int)getRightmostSetBit(n));
    printf("Is one bit different? %s\n", isSingleBitDifferent(0x2A, 0x2B) ? "yes" : "no");
    findTwoUniqueNumbers(twoNums, 6, &a, &b);
    printf("Two unique numbers: %u, %u\n", (unsigned int)a, (unsigned int)b);
    printf("Odd/even bits swapped: %u\n", (unsigned int)swapOddEvenBits(n));
    printf("Rightmost set bit cleared: %u\n", (unsigned int)clearRightmostSetBit(n));
    printf("Bits reversed: %u\n", (unsigned int)reverseBits(n));
    printf("Bits reversed without loop: %u\n", (unsigned int)reverseBitsWithoutLoop(n));
    printf("Sum without plus: %u\n", (unsigned int)addWithoutPlus(0x2A, 0x5));
    printf("Rotate left by 3: %u\n", (unsigned int)rotateLeft(n, 3));
    printf("Rotate right by 3: %u\n", (unsigned int)rotateRight(n, 3));
    printf("Next power of two: %u\n", (unsigned int)nextPowerOfTwo(n));
    printf("Leading zeros: %u\n", (unsigned int)countLeadingZeros(n));

    return 0;
}
