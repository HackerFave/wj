cmake_project(SERVICE_BROKER)

set(SERVICE_BROKER_ROOT     ${SERVICE_BROKER_SOURCE_DIR})

set(SERVICE_BROKER_SRCS     ${SERVICE_BROKER_ROOT}/src
                      )

set(SERVICE_BROKER_INCS     ${CMAKE_FRAMEWORK_ROOT}/zmq_wrapper/include
                      ${CMAKE_FRAMEWORK_ROOT}/fbs/out
                      ${CMAKE_FRAMEWORK_ROOT}/fbs/include
                      )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=deprecated-declarations -Wno-deprecated-declarations")
set(SERVICE_BROKER_LIBS zmq_wrapper pthread)
set(PROGRAM_NAME       service_broker)

cmake_module(
    NAME     ${PROGRAM_NAME}
    TYPE     APP
    SOURCE   ${SERVICE_BROKER_SRCS}
    INCLUDE  ${SERVICE_BROKER_INCS}
    LINK_LIB ${SERVICE_BROKER_LIBS}
    PACKAGE  ${PROGRAM_NAME}
    INSTALL  ${SERVICE_BROKER_ROOT}/conf
)
