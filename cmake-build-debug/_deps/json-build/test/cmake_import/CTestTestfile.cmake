# CMake generated Testfile for 
# Source directory: /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/cmake_import
# Build directory: /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test/cmake_import
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cmake_import_configure "/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake" "-G" "Unix Makefiles" "-A" "" "-Dnlohmann_json_DIR=/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build" "/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/cmake_import/project")
set_tests_properties(cmake_import_configure PROPERTIES  FIXTURES_SETUP "cmake_import" _BACKTRACE_TRIPLES "/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/cmake_import/CMakeLists.txt;1;add_test;/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/cmake_import/CMakeLists.txt;0;")
add_test(cmake_import_build "/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake" "--build" ".")
set_tests_properties(cmake_import_build PROPERTIES  FIXTURES_REQUIRED "cmake_import" _BACKTRACE_TRIPLES "/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/cmake_import/CMakeLists.txt;8;add_test;/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/cmake_import/CMakeLists.txt;0;")
