/* A quick sample test. See ext/testing.h for more details on writing tests. */

#include <testing.h>

void samplePassingTest(test_data *main) { PASS_TEST(); }

void sampleFailingTest(test_data *main) {
  FAIL_TEST("This test always fails!");
}

int main() {
  INIT();

  RUN(samplePassingTest);
  RUN(sampleFailingTest);

  CONCLUDE();
}
