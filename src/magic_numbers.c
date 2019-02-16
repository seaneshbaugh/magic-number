#include <stdlib.h>
#include <stdint.h>

static const uint8_t two7 = 0x80;
static const uint16_t two8 = 0x100;
static const uint16_t two15 = 0x8000;
static const uint32_t two16 = 0x10000;
static const uint32_t two31 = 0x80000000;
static const uint64_t two32 = 0x100000000;
static const uint64_t two63 = 0x8000000000000000;
static const __uint128_t two64 = 0x10000000000000000;

uint8_t unsigned8BitMagicNumber(uint8_t divisor) {
  uint8_t addind = 0;

  uint8_t nc = (uint8_t)(two8 - 1 - (two8 - (uint16_t)divisor) % (uint16_t)divisor);

  uint8_t p = 7;

  uint8_t q1 = two7 / nc;

  uint8_t r1 = two7 - q1 * nc;

  uint8_t q2 = (two7 - 1) / divisor;

  uint8_t r2 = (two7 - 1) - q2 * divisor;

  uint8_t delta = 0;

  do {
    p = p + 1;

    if (r1 >= nc - r1) {
      q1 = 2 * q1 + 1;

      r1 = 2 * r1 - nc;
    } else {
      q1 = 2 * q1;

      r1 = 2 * r1;
    }

    if (r2 + 1 >= divisor - r2) {
      if (q2 >= two7 - 1) {
        addind = 1;
      }

      q2 = 2 * q2 + 1;

      r2 = 2 * r2 + 1 - divisor;
    } else {
      if (q2 >= two7) {
        addind = 1;
      }

      q2 = 2 * q2;

      r2 = 2 * r2 + 1;
    }

    delta = divisor - 1 - r2;
  } while (p < 16 && (q1 < delta || (q1 == delta && r1 == 0)));

  uint16_t result = q2 + 1;

  return result;
}

uint16_t unsigned16BitMagicNumber(uint16_t divisor) {
  uint16_t addind = 0;

  uint16_t nc = (uint16_t)(two16 - 1 - (two16 - (uint32_t)divisor) % (uint32_t)divisor);

  uint16_t p = 15;

  uint16_t q1 = two15 / nc;

  uint16_t r1 = two15 - q1 * nc;

  uint16_t q2 = (two15 - 1) / divisor;

  uint16_t r2 = (two15 - 1) - q2 * divisor;

  uint16_t delta = 0;

  do {
    p = p + 1;

    if (r1 >= nc - r1) {
      q1 = 2 * q1 + 1;

      r1 = 2 * r1 - nc;
    } else {
      q1 = 2 * q1;

      r1 = 2 * r1;
    }

    if (r2 + 1 >= divisor - r2) {
      if (q2 >= two15 - 1) {
        addind = 1;
      }

      q2 = 2 * q2 + 1;

      r2 = 2 * r2 + 1 - divisor;
    } else {
      if (q2 >= two15) {
        addind = 1;
      }

      q2 = 2 * q2;

      r2 = 2 * r2 + 1;
    }

    delta = divisor - 1 - r2;
  } while (p < 32 && (q1 < delta || (q1 == delta && r1 == 0)));

  uint16_t result = q2 + 1;

  return result;
}

uint32_t unsigned32BitMagicNumber(uint32_t divisor) {
  uint32_t addind = 0;

  uint32_t nc = (uint32_t)(two32 - 1 - (two32 - (uint64_t)divisor) % (uint64_t)divisor);

  uint32_t p = 31;

  uint32_t q1 = two31 / nc;

  uint32_t r1 = two31 - q1 * nc;

  uint32_t q2 = (two31 - 1) / divisor;

  uint32_t r2 = (two31 - 1) - q2 * divisor;

  uint32_t delta = 0;

  do {
    p = p + 1;

    if (r1 >= nc - r1) {
      q1 = 2 * q1 + 1;

      r1 = 2 * r1 - nc;
    } else {
      q1 = 2 * q1;

      r1 = 2 * r1;
    }

    if (r2 + 1 >= divisor - r2) {
      if (q2 >= two31 - 1) {
        addind = 1;
      }

      q2 = 2 * q2 + 1;

      r2 = 2 * r2 + 1 - divisor;
    } else {
      if (q2 >= two31) {
        addind = 1;
      }

      q2 = 2 * q2;

      r2 = 2 * r2 + 1;
    }

    delta = divisor - 1 - r2;
  } while (p < 64 && (q1 < delta || (q1 == delta && r1 == 0)));

  uint32_t result = q2 + 1;

  return result;
}

uint64_t unsigned64BitMagicNumber(uint64_t divisor) {
  uint64_t addind = 0;

  uint64_t nc = (uint64_t)(two64 - 1 - (two64 - (__uint128_t)divisor) % (__uint128_t)divisor);

  uint64_t p = 63;

  uint64_t q1 = two63 / nc;

  uint64_t r1 = two63 - q1 * nc;

  uint64_t q2 = (two63 - 1) / divisor;

  uint64_t r2 = (two63 - 1) - q2 * divisor;

  uint64_t delta = 0;

  do {
    p = p + 1;

    if (r1 >= nc - r1) {
      q1 = 2 * q1 + 1;

      r1 = 2 * r1 - nc;
    } else {
      q1 = 2 * q1;

      r1 = 2 * r1;
    }

    if (r2 + 1 >= divisor - r2) {
      if (q2 >= two63 - 1) {
        addind = 1;
      }

      q2 = 2 * q2 + 1;

      r2 = 2 * r2 + 1 - divisor;
    } else {
      if (q2 >= two63) {
        addind = 1;
      }

      q2 = 2 * q2;

      r2 = 2 * r2 + 1;
    }

    delta = divisor - 1 - r2;
  } while (p < 128 && (q1 < delta || (q1 == delta && r1 == 0)));

  uint64_t result = q2 + 1;

  return result;
}
