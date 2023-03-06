cmake_project(MSG_RECV)

set(MSG_RECV_ROOT     ${MSG_RECV_SOURCE_DIR})

set(MSG_RECV_SRCS     ${MSG_RECV_ROOT}/src
                      )

set(MSG_RECV_INCS     ${CMAKE_FRAMEWORK_ROOT}/zmq_wrapper/include
                      ${CMAKE_FRAMEWORK_ROOT}/fbs/out
                      ${CMAKE_FRAMEWORK_ROOT}/fbs/include
                      ${CMAKE_FRAMEWORK_ROOT}/common/include
                    )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=deprecated-declarations -Wno-deprecated-declarations")
set(MSG_RECV_LIBS zmq_wrapper pthread)
set(PROGRAM_NAME       message_recv)

cmake_module(
    NAME     ${PROGRAM_NAME}
    TYPE     APP
    SOURCE   ${MSG_RECV_SRCS}
    INCLUDE  ${MSG_RECV_INCS}
    LINK_LIB ${MSG_RECV_LIBS}
    PACKAGE  ${PROGRAM_NAME}
)
