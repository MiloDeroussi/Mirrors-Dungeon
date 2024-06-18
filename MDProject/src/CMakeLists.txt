
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)
add_library(src ${SOURCES}  "Donjon.cpp" "USalle.h" "USalle.cpp" "HSalle.h" "HSalle.cpp")
target_include_directories(src PUBLIC ./)
target_link_libraries(src PUBLIC pugixml sfml-graphics sfml-audio)