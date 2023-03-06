cmake_project(MSG_SEND)

set(MSG_SEND_ROOT     ${MSG_SEND_SOURCE_DIR})

set(MSG_SEND_SRCS     ${MSG_SEND_ROOT}/src
                      )

set(MSG_SEND_INCS     ${CMAKE_FRAMEWORK_ROOT}/zmq_wrapper/include
                      ${CMAKE_FRAMEWORK_ROOT}/fbs/out
                      ${CMAKE_FRAMEWORK_ROOT}/fbs/include
                      ${CMAKE_FRAMEWORK_ROOT}/common/include
                    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=deprecated-declarations -Wno-deprecated-declarations")
set(MSG_SEND_CONF ${MSG_SEND_ROOT}/conf)
set(MSG_SEND_LIBS zmq_wrapper pthread)
set(PROGRAM_NAME       message_send)

cmake_module(
    NAME     ${PROGRAM_NAME}
    TYPE     APP
    SOURCE   ${MSG_SEND_SRCS}
    INCLUDE  ${MSG_SEND_INCS}
    LINK_LIB ${MSG_SEND_LIBS}
    PACKAGE  ${PROGRAM_NAME}
    INSTALL  ${MSG_SEND_CONF}
)
