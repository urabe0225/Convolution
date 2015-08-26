# Convolution CMake config file
#
# This file sets the following variables:
# Convolution_FOUND - Always TRUE.
# Convolution_INCLUDE_DIRS - Directories containing the Convolution include files.
# Convolution_IDL_DIRS - Directories containing the Convolution IDL files.
# Convolution_LIBRARIES - Libraries needed to use Convolution.
# Convolution_DEFINITIONS - Compiler flags for Convolution.
# Convolution_VERSION - The version of Convolution found.
# Convolution_VERSION_MAJOR - The major version of Convolution found.
# Convolution_VERSION_MINOR - The minor version of Convolution found.
# Convolution_VERSION_REVISION - The revision version of Convolution found.
# Convolution_VERSION_CANDIDATE - The candidate version of Convolution found.

message(STATUS "Found Convolution-1.0.0")
set(Convolution_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(Convolution_INCLUDE_DIRS
#    "/usr/local/include/convolution-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(Convolution_IDL_DIRS
#    "/usr/local/include/convolution-1/idl")
set(Convolution_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(Convolution_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(Convolution_LIBRARIES
        "/usr/local/components/lib/libconvolution.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(Convolution_LIBRARIES
        "/usr/local/components/lib/libconvolution.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(Convolution_DEFINITIONS ${<dependency>_DEFINITIONS})

set(Convolution_VERSION 1.0.0)
set(Convolution_VERSION_MAJOR 1)
set(Convolution_VERSION_MINOR 0)
set(Convolution_VERSION_REVISION 0)
set(Convolution_VERSION_CANDIDATE )

