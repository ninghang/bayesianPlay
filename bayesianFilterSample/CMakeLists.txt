CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(test)
ADD_DEFINITIONS(" -O3")
# GSL
SET(BFILT_LIB bfilt)



# Executables and "stand-alone " librairies
ADD_EXECUTABLE (test
main.cpp
ar_process.cpp
)
# Linkage
TARGET_LINK_LIBRARIES(test
${BFILT_LIB}
)

