include(_CPM)

add_library(sdk_dependencies INTERFACE)

include(concurrentqueue)
target_link_libraries(sdk_dependencies INTERFACE concurrentqueue)

# other deps
# include(lib)
# target_link_libraries(sdk_dependencies INTERFACE x::y)