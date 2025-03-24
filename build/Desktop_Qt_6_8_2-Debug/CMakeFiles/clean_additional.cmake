# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtWeatherApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtWeatherApp_autogen.dir/ParseCache.txt"
  "QtWeatherApp_autogen"
  )
endif()
