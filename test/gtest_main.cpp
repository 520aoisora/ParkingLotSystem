/*
 * gtest_main.cpp
 *
 *  Created on: 20 Sep 2017
 *      Author: Yi
 */

// gtest_main.cpp
#include <stdio.h>
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
