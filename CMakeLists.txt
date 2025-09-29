# CMakeList.txt : CMake project for TestPlatformer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (TestPlatformer)

include(FetchContent)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git 
	GIT_TAG 016bea9491ccafc3529019fe1d403885a8b3a6ae
)
FetchContent_MakeAvailable(SFML)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)

set(SOURCE_FILES "src/main.cpp")

# Add source to this project's executable.
add_executable (TestPlatformer ${SOURCE_FILES} "src/Game.h" "src/Game.cpp" "src/Player/Player.h" "src/Player/Player.cpp")
target_link_libraries(TestPlatformer PRIVATE sfml-graphics sfml-window sfml-system sfml-network sfml-audio)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TestPlatformer PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
