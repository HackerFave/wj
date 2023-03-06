cmake_project(TCP_PROXY)

set(TCP_PROXY_ROOT     ${TCP_PROXY_SOURCE_DIR})

set(TCP_PROXY_SRCS     ${TCP_PROXY_ROOT}/src
                      )

set(TCP_PROXY_INCS     ${CMAKE_FRAMEWORK_ROOT}/zmq_wrapper/include
                      ${CMAKE_PROJECT_ROOT}/../third_party/cppzmq/include
                      ${CMAKE_PROJECT_ROOT}/../third_party/zeromq/linux/include
                      )

set(TCP_PROXY_LIBS   zmq)
set(PROGRAM_NAME    tcp_proxy)

cmake_module(
    NAME     ${PROGRAM_NAME}
    TYPE     APP
    SOURCE   ${TCP_PROXY_SRCS}
    INCLUDE  ${TCP_PROXY_INCS}
    LINK_LIB ${TCP_PROXY_LIBS}
    PACKAGE  ${PROGRAM_NAME}
    INSTALL  ${TCP_PROXY_ROOT}/conf
)
