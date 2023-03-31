#
# CMakeLists.txt -- CMake build script
#
# Copyright 2023 alex@staticlibs.net
#
# %Begin-Header%
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, and the entire permission notice in its entirety,
#    including the disclaimer of warranties.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote
#    products derived from this software without specific prior
#    written permission.
#
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ALL OF
# WHICH ARE HEREBY DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
# OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
# BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
# USE OF THIS SOFTWARE, EVEN IF NOT ADVISED OF THE POSSIBILITY OF SUCH
# DAMAGE.
# %End-Header%
#

cmake_minimum_required ( VERSION 3.0 )

project ( uuid C )

add_library ( ${PROJECT_NAME} STATIC
    gen_uuid_win.c
    unparse.c
    uuid.h )
        
target_include_directories ( ${PROJECT_NAME} BEFORE PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR} )
 
target_include_directories ( ${PROJECT_NAME} BEFORE PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR} )

enable_testing()

add_executable ( ${PROJECT_NAME}_test
    test.c
    uuid.h )

target_include_directories ( ${PROJECT_NAME}_test BEFORE PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR} )

target_link_libraries ( ${PROJECT_NAME}_test PRIVATE
    ${PROJECT_NAME}
    rpcrt4 )

add_test ( ${PROJECT_NAME}_test
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}_test.exe )

install ( TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib )

install ( FILES uuid.h
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include )
