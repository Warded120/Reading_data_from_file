# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Reading_data_from_file_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Reading_data_from_file_autogen.dir\\ParseCache.txt"
  "Reading_data_from_file_autogen"
  )
endif()
