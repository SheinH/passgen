cmake_minimum_required(VERSION 3.15)
project(passgen C)


set(CMAKE_C_STANDARD 11)

add_executable(passgen
        passgen.c)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBSODIUM libsodium)

if(STATIC_LIBSODIUM)
    if(BUILD_STATIC_EXECUTABLES)
        set_target_properties(passgen PROPERTIES LINK_SEARCH_START_STATIC 1)
        set_target_properties(passgen PROPERTIES LINK_SEARCH_END_STATIC 1)
    endif()
    set(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
endif()

find_path(SODIUM_INCLUDE_DIR sodium.h HINTS ${LIBSODIUM_INCLUDE_DIRS} /usr/local/include /opt/local/include /opt/include)
find_library(SODIUM_LIBRARY NAMES sodium HINTS ${LIBSODIUM_LIBRARY_DIRS} /usr/local/lib /opt/local/lib /opt/lib)

if(STATIC_LIBSODIUM)
    set(LIBSODIUM_CFLAGS_OTHER ${LIBSODIUM_STATIC_CFLAGS_OTHER})
    set(LIBSODIUM_LDFLAGS_OTHER ${LIBSODIUM_STATIC_LDFLAGS_OTHER})
endif()

target_include_directories(passgen PUBLIC ${SODIUM_INCLUDE_DIR})
target_compile_options(passgen PUBLIC ${LIBSODIUM_CFLAGS} ${LIBSODIUM_CFLAGS_OTHER})
target_link_libraries(passgen ${SODIUM_LIBRARY} ${LIBSODIUM_LDFLAGS_OTHER})