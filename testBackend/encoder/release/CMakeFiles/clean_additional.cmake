# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\encoder_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\encoder_autogen.dir\\ParseCache.txt"
  "encoder_autogen"
  )
endif()
