# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

project( out )


cmake_minimum_required(VERSION 2.8.11)

# CGAL and its components
find_package( CGAL QUIET COMPONENTS Core )

if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()


# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )

  message(STATUS "This project requires the Boost library, and will not be compiled.")

  return()  

endif()

# include for local directory
include( ${CGAL_USE_FILE} )
include( CGAL_CreateSingleSourceCGALProgram )
# include for local package


# Creating entries for target: out
# ############################

add_executable( out  antenna.cpp )

add_to_cached_list( CGAL_EXECUTABLE_TARGETS out )

# Link the executable to CGAL and third-party libraries
target_link_libraries(out   ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} )

