/*
 * Defines the test runner executable. This is the executable run by `make test`
 * when running tests.
 *
 * This executable takes in all test file names and runs them in parallel.
 * Tests files executables should return the total number of failing tests.
 * E.x. A working test file should return 0, while a test file containing 2
 * failing tests should return 2.
 *
 * See ext/testing.h for more information about writing test files.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int failed_tests = 0;
  printf("\nRunning Tests:\n");
  for (int i = 1; i < argc; i++) {
    printf("%s\n:", argv[i]);

    int ret = system(argv[i]);
    if (WIFEXITED(ret)) {
        failed_tests += WEXITSTATUS(ret);
    }
  }

  if (failed_tests == 0) {
    printf("\nThere were no failing tests!\n");
  } else {
    printf("\nThere were %d failing tests.\n", failed_tests);
  }

  return 0;
}
