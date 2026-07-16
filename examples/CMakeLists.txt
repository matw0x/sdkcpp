add_executable(sandbox 
    locator/Locator.cpp
)

target_link_libraries(sandbox PRIVATE sdk::sdk)