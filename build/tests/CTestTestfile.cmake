# CMake generated Testfile for 
# Source directory: D:/university/TrustedSoftwareDevelopment/Programs/cpp-training/tests
# Build directory: D:/university/TrustedSoftwareDevelopment/Programs/cpp-training/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(training_main "D:/university/TrustedSoftwareDevelopment/Programs/cpp-training/build/tests/training_main.exe")
set_tests_properties(training_main PROPERTIES  _BACKTRACE_TRIPLES "D:/university/TrustedSoftwareDevelopment/Programs/cpp-training/tests/CMakeLists.txt;8;ADD_TEST;D:/university/TrustedSoftwareDevelopment/Programs/cpp-training/tests/CMakeLists.txt;0;")
subdirs("googletest")
