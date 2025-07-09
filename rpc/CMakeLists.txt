find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(walletrpc ${CURL_LIBRARIES})
