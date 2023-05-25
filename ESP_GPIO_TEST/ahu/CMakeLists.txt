# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

target_sources(app PRIVATE src/main.c)
target_include_directories(app PRIVATE 
    /home/user/csse4011/repo/oslib/scu_drivers/scu_sensors/
    /home/user/csse4011/repo/oslib/scu_drivers/scu_hci/
    /home/user/csse4011/repo/oslib/ahu_drivers/ahu_hci/)


target_sources(app PRIVATE
    src/main.c
    /home/user/csse4011/repo/oslib/scu_drivers/scu_sensors/scu_sensors.c
    /home/user/csse4011/repo/oslib/scu_drivers/scu_hci/scu_hci.c
    /home/user/csse4011/repo/oslib/ahu_drivers/ahu_hci/ahu_hci.c)
