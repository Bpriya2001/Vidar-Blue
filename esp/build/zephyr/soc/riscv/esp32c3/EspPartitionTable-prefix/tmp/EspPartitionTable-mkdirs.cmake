# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/user/csse4011/zephyrproject/modules/hal/espressif/components/partition_table"
  "/home/user/csse4011/Vidar-Blue/esp/build/esp-idf/build"
  "/home/user/csse4011/Vidar-Blue/esp/build/zephyr/soc/riscv/esp32c3/EspPartitionTable-prefix"
  "/home/user/csse4011/Vidar-Blue/esp/build/zephyr/soc/riscv/esp32c3/EspPartitionTable-prefix/tmp"
  "/home/user/csse4011/Vidar-Blue/esp/build/zephyr/soc/riscv/esp32c3/EspPartitionTable-prefix/src/EspPartitionTable-stamp"
  "/home/user/csse4011/Vidar-Blue/esp/build/zephyr/soc/riscv/esp32c3/EspPartitionTable-prefix/src"
  "/home/user/csse4011/Vidar-Blue/esp/build/zephyr/soc/riscv/esp32c3/EspPartitionTable-prefix/src/EspPartitionTable-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/user/csse4011/Vidar-Blue/esp/build/zephyr/soc/riscv/esp32c3/EspPartitionTable-prefix/src/EspPartitionTable-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/user/csse4011/Vidar-Blue/esp/build/zephyr/soc/riscv/esp32c3/EspPartitionTable-prefix/src/EspPartitionTable-stamp${cfgdir}") # cfgdir has leading slash
endif()
