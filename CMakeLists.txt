# CMakeList.txt : CMake project for LinkedLists, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("LinkedLists")

# Add source to this project's executable.
#add_executable (LinkedLists "LinkedLists.cpp" "LinkedLists.h" "RecursiveLinkedLists.cpp")
#add_executable (LinkedLists  "LinkedLists.h" "RecursiveLinkedLists.cpp" "CountAndSum.cpp")
#add_executable (LinkedLists  "LinkedLists.h" "CountAndSum.cpp")
#add_executable (LinkedLists  "LinkedLists.h" "maxElement.cpp" "linearSearch.cpp")
#add_executable (LinkedLists  "LinkedLists.h" "linearSearch.cpp")
#add_executable (LinkedLists  "LinkedLists.h" "insertion.cpp" "sortedListInsert.cpp")
#add_executable (LinkedLists  "LinkedLists.h" "sortedListInsert.cpp" "deleteNode.cpp")
#add_executable (LinkedLists  "LinkedLists.h"  "deleteNode.cpp" "checkIfSorted.cpp")
#add_executable (LinkedLists  "LinkedLists.h"  "checkIfSorted.cpp" "removeDuplicates.cpp")
#add_executable (LinkedLists  "LinkedLists.h"  "removeDuplicates.cpp" "reverseLinkedList.cpp")
#add_executable (LinkedLists  "LinkedLists.h"  "reverseLinkedList.cpp" "concatenateAndMerge.cpp")
add_executable (LinkedLists  "LinkedLists.h" "concatenateAndMerge.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LinkedLists PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
