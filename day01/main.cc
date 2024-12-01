#include <glog/logging.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_split.h"
#include "absl/container/flat_hash_set.h"
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/status/statusor.h"
#include "day01/solution.h"

ABSL_FLAG(std::string, in_file, "", "file with input data");
ABSL_FLAG(bool, second_part, false, "whether to run the 2nd part");

std::vector<std::string> ReadInputStrings() {
  std::ifstream t(absl::GetFlag(FLAGS_in_file));
  t.seekg(0, std::ios::end);
  size_t size = t.tellg();
  std::string buffer(size, ' ');
  t.seekg(0);
  t.read(&buffer[0], size);
  return absl::StrSplit(buffer, "\n");
}

std::vector<int32_t> ReadInput() {
  std::fstream myfile(absl::GetFlag(FLAGS_in_file), std::ios_base::in);
  std::vector<int32_t> input;
  int32_t number;
  while (myfile >> number) {
    input.push_back(number);
  }
  return input;
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  absl::ParseCommandLine(argc, argv);

  absl::StatusOr<int32_t> result;
  auto numbers = ReadInputStrings();
  for (const auto& i : numbers){
    LOG(INFO) << i;
  }
  auto first = !absl::GetFlag(FLAGS_second_part);
  if (first) {
    result = Solve(numbers);
  } else {
    result = Solve2(numbers);
  }
  if (!result.ok()) {
    LOG(FATAL) << result.status().message();
  }
  std::cout << *result << std::endl;

  return EXIT_SUCCESS;
}
