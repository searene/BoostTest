# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Add Boost
include_directories(${MY_BOOST_INC_DIR})
add_library(boost_iostreams SHARED IMPORTED)
set_target_properties(boost_iostreams PROPERTIES IMPORTED_LOCATION ${MY_BOOST_LIBS_DIR}/${ANDROID_ABI}/libboost_iostreams.so)
add_library(boost_system SHARED IMPORTED)
set_target_properties(boost_system PROPERTIES IMPORTED_LOCATION ${MY_BOOST_LIBS_DIR}/${ANDROID_ABI}/libboost_system.so)
add_library(boost_filesystem SHARED IMPORTED)
set_target_properties(boost_filesystem PROPERTIES IMPORTED_LOCATION ${MY_BOOST_LIBS_DIR}/${ANDROID_ABI}/libboost_filesystem.so)
add_library(boost_stacktrace_basic SHARED IMPORTED)
set_target_properties(boost_stacktrace_basic PROPERTIES IMPORTED_LOCATION ${MY_BOOST_LIBS_DIR}/${ANDROID_ABI}/libboost_stacktrace_basic.so)
message(${MY_BOOST_LIBS_DIR}/${ANDROID_ABI}/libboost_stacktrace_basic.so)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib

        boost_iostreams
        boost_filesystem
        boost_system

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})