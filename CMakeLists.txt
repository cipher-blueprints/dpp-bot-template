cmake_minimum_required(VERSION 3.17)
project(bot VERSION 1.0 DESCRIPTION "Bot description")

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(PkgConfig REQUIRED)
pkg_search_module(dpp REQUIRED dpp)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
if (USING_DOCKER MATCHES TRUE)
    link_libraries("-static")
endif ()

target_link_libraries(${PROJECT_NAME} dpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${DPP_INCLUDE_DIR}) 
target_link_libraries(${PROJECT_NAME} ${ZLIB_LIBRARIES} ${OPENSSL_CRYPTO_LIBRARY} ${OPENSSL_SSL_LIBRARY})

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)