cmake_minimum_required(VERSION 3.0.0)
project(aspect-ratio-c VERSION 0.1.0)

include(CTest)
enable_testing()

set(INCLUDES_DIR includes)
set(SOURCES_DIR src)
set(HEADER_FILES 
  ${INCLUDES_DIR}/aspectratio.h
)
set(DEP_SRC_FILES
  ${SOURCES_DIR}/to_number.c
)

add_executable(toaspectratio ${SOURCES_DIR}/toaspectratio.c ${DEP_SRC_FILES} ${HEADER_FILES})
add_executable(checkaspectratio ${SOURCES_DIR}/checkaspectratio.c ${DEP_SRC_FILES} ${HEADER_FILES})
target_include_directories(toaspectratio PRIVATE ${SOURCES_DIR} ${INCLUDES_DIR})
target_include_directories(checkaspectratio PRIVATE ${SOURCES_DIR} ${INCLUDES_DIR})
install(TARGETS toaspectratio checkaspectratio DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
