#Include the current directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#Gather source and header files for current module
file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

# Define current module as a library
add_library(commercial ${SOURCES} ${HEADERS})

# Add src as an include directory for this module
target_include_directories(commercial PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# If commercial depends on other modules, link them here. For example: 
# target_link_libraries(commercial PUBLIC industrial landmark residential)