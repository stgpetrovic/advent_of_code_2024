#include <vector>

#include <string>

#include "absl/strings/str_split.h"
#include "day01/solution.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Day01, First) {
  std::string input =R"(3   4
4   3
2   5
1   3
3   9
3   3)";
  auto result = Solve(absl::StrSplit(input, "\n"));
  ASSERT_EQ(result, 11);
}

TEST(Day01, Second) {
  std::string input =R"(3   4
4   3
2   5
1   3
3   9
3   3)";
  auto result = Solve2(absl::StrSplit(input, "\n"));
  ASSERT_EQ(result, 31);
}
