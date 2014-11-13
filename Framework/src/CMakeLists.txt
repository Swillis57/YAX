file(GLOB_RECURSE FRAMEWORK_SRC)

#include(Audio/CMakeLists.txt)
#include(Curves/CMakeLists.txt)
#include(Design/CMakeLists.txt)
#include(Geometry/CMakeLists.txt)
#include(Graphics/CMakeLists.txt)
#include(Input/CMakeLists.txt)
#include(Math/CMakeLists.txt)
#include(Media/CMakeLists.txt)
#include(Net/CMakeLists.txt)
#include(Storage/CMakeLists.txt)

add_library(YAX STATIC ${FRAMEWORK_SRC})

target_link_libraries(YAX
	opengl32.lib
	glewd.lib
	glfw3.lib
)

set_target_properties(YAX
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib"
)