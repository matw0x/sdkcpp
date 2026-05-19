include(_CPM.cmake)

add_library(sdk_dependencies INTERFACE)

include(concurrentqueue.cmake)
target_link_libraries(sdk_dependencies INTERFACE moodycamel::concurrentqueue)

# other deps
# include(lib.cmake)
# target_link_libraries(sdk_dependencies INTERFACE x::y)