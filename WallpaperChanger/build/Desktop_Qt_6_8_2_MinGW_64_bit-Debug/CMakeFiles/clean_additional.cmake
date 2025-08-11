# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\WallpaperChanger_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WallpaperChanger_autogen.dir\\ParseCache.txt"
  "WallpaperChanger_autogen"
  )
endif()
