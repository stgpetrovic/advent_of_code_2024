cc_library(
  name = "solution",
  deps = [
    "@abseil-cpp//absl/container:flat_hash_set",
    "@glog//:glog",
    "@abseil-cpp//absl/status:statusor",
    "@abseil-cpp//absl/container:flat_hash_map",
  ],
  srcs = ["solution.cc"],
  hdrs = ["solution.h"],
)

cc_test(
    name = "test",
    srcs = ["test.cc"],
    deps = [
        ":solution",
        "@googletest//:gtest_main",
        "@abseil-cpp//absl/strings",
    ],
)

cc_binary(
  name = "main",
  deps = [
    ":solution",
    "@abseil-cpp//absl/flags:flag",
    "@abseil-cpp//absl/flags:parse",
  ],
  srcs = ["main.cc"],
)
