cmake_project(IPC_PROXY)

set(IPC_PROXY_ROOT     ${IPC_PROXY_SOURCE_DIR})

set(IPC_PROXY_SRCS     ${IPC_PROXY_ROOT}/src
                      )

set(IPC_PROXY_INCS     ${CMAKE_FRAMEWORK_ROOT}/zmq_wrapper/include
                      ${CMAKE_PROJECT_ROOT}/../third_party/cppzmq/include
                      ${CMAKE_PROJECT_ROOT}/../third_party/zeromq/linux/include
                      )

set(IPC_PROXY_LIBS   zmq)
set(PROGRAM_NAME    ipc_proxy)

cmake_module(
    NAME     ${PROGRAM_NAME}
    TYPE     APP
    SOURCE   ${IPC_PROXY_SRCS}
    INCLUDE  ${IPC_PROXY_INCS}
    LINK_LIB ${IPC_PROXY_LIBS}
    PACKAGE  ${PROGRAM_NAME}
    INSTALL  ${IPC_PROXY_ROOT}/conf
)
