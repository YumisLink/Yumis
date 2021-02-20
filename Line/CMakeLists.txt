cmake_minimum_required(VERSION 3.0.0)
project(line VERSION 0.1.0)

set(PAINTERENGINE_DIR ${PROJECT_SOURCE_DIR}/PainterEngine)
set(PAINTERENGINE_PROJECT_DIR ${PROJECT_SOURCE_DIR})

include_directories(${PAINTERENGINE_DIR})
include_directories(${PAINTERENGINE_DIR}/platform/windows)
include_directories(${PAINTERENGINE_PROJECT_DIR})

aux_source_directory(${PAINTERENGINE_PROJECT_DIR} PROJECT_DIR_SRC)
aux_source_directory(${PAINTERENGINE_DIR}/platform/windows PAINTERENGINE_PLATFORM_WINDOWS_SOURCES)
aux_source_directory(${PAINTERENGINE_DIR}/core PAINTERENGINE_CORE_SOURCES)
aux_source_directory(${PAINTERENGINE_DIR}/kernel PAINTERENGINE_KERNEL_SOURCES)
aux_source_directory(${PAINTERENGINE_DIR}/architecture PAINTERENGINE_ARCH_SOURCES)

add_executable(line ${PROJECT_DIR_SRC}
                    ${PAINTERENGINE_PLATFORM_WINDOWS_SOURCES}
                    ${PAINTERENGINE_CORE_SOURCES}
                    ${PAINTERENGINE_KERNEL_SOURCES}
                    ${PAINTERENGINE_ARCH_SOURCES}
                    Graphic.cpp)