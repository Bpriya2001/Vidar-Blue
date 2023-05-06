# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/user/csse4011/zephyrproject/modules/hal/espressif/components/bootloader/subproject"
  "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf/build/bootloader"
  "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf"
  "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf/tmp"
  "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf/src/EspIdfBootloader-stamp"
  "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf/src"
  "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf/src/EspIdfBootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf/src/EspIdfBootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf/src/EspIdfBootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
