#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "magic_numbers.h"

int main(int argc, char* argv[]) {
  uint8_t unsigned8BitDivisor = 1;
  uint16_t unsigned16BitDivisor = 1;
  uint32_t unsigned32BitDivisor = 1;
  uint64_t unsigned64BitDivisor = 1;
  size_t bitWidth = 64;
  bool divisorSigned = false;

  opterr = 0;

  int code = 0;

  while ((code = getopt(argc, argv, "b:s")) != -1) {
    switch (code) {
    case 'b':
      bitWidth = strtoull(optarg, NULL, 10);

      break;
    case 's':
      divisorSigned = true;

      break;
    case '?':
      if (optopt == 'b') {
        fprintf(stderr, "Error: option -b requires an argument.\n");
      } else {
        if (isprint(optopt)) {
          fprintf(stderr, "Error: unknown option \"-%c\".\n", optopt);
        } else {
          fprintf(stderr, "Error: unknown option character \"\\x%x\".\n", optopt);
        }
      }

      return 1;
    default:
      abort();
    }
  }

  if (optind != argc -1) {
    fprintf(stderr, "Usage: magic-number [-s] [-b bitwidth] divsor.\n");

    return 1;
  }

  if (bitWidth != 8 && bitWidth != 16 && bitWidth != 32 && bitWidth != 64) {
    fprintf(stderr, "Error: bitwidth must be either 8, 16, 32, or 64.\n");

    return 1;
  }

  const char* divisorArg = argv[optind];

  switch (bitWidth) {
  case 8:
    if (divisorSigned) {
      fprintf(stderr, "Unsupported sign.\n");

      return 1;
    } else {
      unsigned8BitDivisor = strtoul(divisorArg, NULL, 10);

      printf("%d\n", unsigned8BitMagicNumber(unsigned8BitDivisor));
    }

    break;
  case 16:
    if (divisorSigned) {
      fprintf(stderr, "Unsupported sign.\n");

      return 1;
    } else {
      unsigned16BitDivisor = strtoul(divisorArg, NULL, 10);

      printf("%d\n", unsigned16BitMagicNumber(unsigned16BitDivisor));
    }

    break;
  case 32:
    if (divisorSigned) {
      fprintf(stderr, "Unsupported sign.\n");

      return 1;
    } else {
      unsigned32BitDivisor = strtoul(divisorArg, NULL, 10);

      printf("%" PRIu32 "\n", unsigned32BitMagicNumber(unsigned32BitDivisor));
    }

    break;
  case 64:
    if (divisorSigned) {
      fprintf(stderr, "Unsupported sign.\n");

      return 1;
    } else {
      unsigned64BitDivisor = strtoull(divisorArg, NULL, 10);

      printf("%" PRIu64 "\n", unsigned64BitMagicNumber(unsigned64BitDivisor));
    }

    break;
  default:
    fprintf(stderr, "Unsupported bitwidth.\n");

    return 1;
  }

  return 0;
}
