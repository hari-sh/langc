#include "bitwise.h"

uint32_t findUniqueNumber(const uint32_t *nums, uint32_t size) {
    uint32_t result = 0;
    uint32_t i;

    for (i = 0; i < size; ++i) {
        result ^= nums[i];
    }

    return result;
}

uint32_t findMissingNumber(const uint32_t *nums, uint32_t size) {
    uint32_t result = size;
    uint32_t i;

    for (i = 0; i < size; ++i) {
        result ^= i ^ nums[i];
    }

    return result;
}

uint32_t findDuplicateNumber(const uint32_t *nums, uint32_t size) {
    uint32_t result = 0;
    uint32_t i;

    for (i = 0; i < size; ++i) {
        result ^= nums[i];
    }

    for (i = 1; i < size; ++i) {
        result ^= i;
    }

    return result;
}

uint32_t findUniqueAmongTriplicates(const uint32_t *nums, uint32_t size) {
    uint32_t ones = 0;
    uint32_t twos = 0;
    uint32_t i;

    for (i = 0; i < size; ++i) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }

    return ones;
}

uint32_t maxXorPair(const uint32_t *nums, uint32_t size) {
    uint32_t max = 0;
    uint32_t i;
    uint32_t j;

    for (i = 0; i < size; ++i) {
        for (j = i + 1; j < size; ++j) {
            if ((nums[i] ^ nums[j]) > max) {
                max = nums[i] ^ nums[j];
            }
        }
    }

    return max;
}

uint32_t maxXorSubarray(const uint32_t *nums, uint32_t size) {
    uint32_t max = 0;
    uint32_t value;
    uint32_t i;
    uint32_t j;

    for (i = 0; i < size; ++i) {
        value = 0;

        for (j = i; j < size; ++j) {
            value ^= nums[j];

            if (value > max) {
                max = value;
            }
        }
    }

    return max;
}

uint32_t getRightmostSetBit(uint32_t n) {
    return n & (~n + 1);
}

int isSingleBitDifferent(uint32_t a, uint32_t b) {
    return isPowerOfTwo(a ^ b);
}

uint32_t xorFromOneToN(uint32_t n) {
    switch (n % 4) {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        default:
            return 0;
    }
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

void findTwoMissingNumbers(const uint32_t *nums, uint32_t size, uint32_t *a, uint32_t *b) {
    uint32_t bit;
    uint32_t result = 0;
    uint32_t i;

    *a = 0;
    *b = 0;

    for (i = 0; i < size; ++i) {
        result ^= nums[i];
    }

    for (i = 1; i <= size + 2; ++i) {
        result ^= i;
    }

    bit = getRightmostSetBit(result);

    for (i = 0; i < size; ++i) {
        if ((nums[i] & bit) != 0) {
            *a ^= nums[i];
        } else {
            *b ^= nums[i];
        }
    }

    for (i = 1; i <= size + 2; ++i) {
        if ((i & bit) != 0) {
            *a ^= i;
        } else {
            *b ^= i;
        }
    }
}
