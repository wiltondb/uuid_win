# Copyright 2023, alex at staticlibs.net
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required ( VERSION 3.0 )

project ( uuid_win C )

add_library ( uuid_win STATIC
    gen_uuid_win.c
    unparse.c
    uuid.h )
        
target_include_directories ( uuid_win BEFORE PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR} )

enable_testing()

add_executable ( uuid_win_test
    test.c
    uuid.h )

target_include_directories ( uuid_win_test BEFORE PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR} )

target_link_libraries ( uuid_win_test PRIVATE
    uuid_win
    rpcrt4 )

add_test ( uuid_win_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/uuid_win_test.exe )

install ( TARGETS uuid_win
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/dist/lib )

install ( FILES uuid.h
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/dist/include )
