set(CMAKE_CPP_COMPILER g++)

set(SRC_LIST 
#    main.cpp
    VM.cpp
    mcc.cpp
    )

include_directories(${MINICL_SOURCE_DIR}/include)
set(EXECUTABLE_OUTPUT_PATH ${MINICL_SOURCE_DIR}/bin)
add_executable(minicl ${SRC_LIST})
link_directories(${MINICL_SOURCE_DIR}/lib)

#target_link_libraries(minicl vm)

