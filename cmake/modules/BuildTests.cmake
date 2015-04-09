remove_definitions(-DQT_USE_QSTRINGBUILDER -DQT_NO_CAST_TO_ASCII -DQT_NO_CAST_FROM_ASCII)
add_definitions(-DFILES_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")
add_definitions(-DFILES_OUTPUT_DIR="${CMAKE_CURRENT_BINARY_DIR}")

macro(build_test __test_name)
    set(_test_name Test${__test_name})
    set(${_test_name}_SRCS ${_test_name}.cpp)
    set(${_test_name}_MOC_SRCS ${_test_name}.h)
    qt_wrap_cpp(${_test_name} ${_test_name}_SRCS ${${_test_name}_MOC_SRCS})
    add_executable(${_test_name} ${${_test_name}_SRCS})
    target_link_libraries(${_test_name} KDb ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY})
if (BUILD_TEST_COVERAGE)
    target_link_libraries(${_test_name} gcov)
endif (BUILD_TEST_COVERAGE)
    add_test(${_test_name} ${CMAKE_CURRENT_BINARY_DIR}/${_test_name})
endmacro()
