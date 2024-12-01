#include "day01/solution.h"

#include <glog/logging.h>

#include <algorithm>
#include <cstdint>
#include <limits>
#include <queue>
#include <string>
#include <vector>

#include "absl/strings/numbers.h"
#include "absl/container/flat_hash_map.h"
#include "absl/strings/match.h"

int32_t Solve(const std::vector<std::string>& in) {
  std::vector<int32_t> as, bs;
  as.reserve(in.size());
  bs.reserve(in.size());
  for (const auto& line : in) {
    int32_t a, b;
    std::sscanf(line.c_str(), "%d  %d", &a, &b);
    as.push_back(a);
    bs.push_back(b);
  }
  absl::c_sort(as);
  absl::c_sort(bs);
  int32_t diff=0;
  for (int i = 0; i < in.size(); ++i) {
    diff += std::abs(bs[i]-as[i]);
  }
  return diff;
}

int32_t Solve2(const std::vector<std::string>& in) {
  std::vector<int32_t> as;
  absl::flat_hash_map<int32_t, size_t> bs;
  as.reserve(in.size());
  bs.reserve(in.size());
  for (const auto& line : in) {
    int32_t a, b;
    std::sscanf(line.c_str(), "%d  %d", &a, &b);
    as.push_back(a);
    if (!bs.contains(b)) {
      bs[b] = 0;
    }
    ++bs[b];
  }
  int32_t score = 0;
  for (const auto& a : as) {
    if (auto b = bs.find(a); b != bs.end()) {
      score += a*b->second;
    }
  }
  return score;
}
