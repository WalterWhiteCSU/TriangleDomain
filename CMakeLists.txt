cmake_minimum_required(VERSION 3.19)
project(triangleDomain)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "C:/Qt/6.1.1/mingw81_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

# openCV
set(OpenCV_DIR D:\\CPPRepo\\opencv3.1\\opencv\\Qt-build\\install)
find_package(OpenCV REQUIRED)
# 包含openCV的库
include_directories(${OpenCV_INCLUDE_DIRS})
set(Opencv_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

## include Eigen
include_directories(include/eigen-3.3.9)

## include rapidjson
include_directories(include)

# 当前目录下的文件
set(SRC_LIST main.cpp mainwindow.cpp mainwindow.h mainwindow.ui dialog.cpp dialog.h dialog.ui InfoManager.h TriangleService.h TestService.cpp TestService.h trianglevwindow.cpp trianglevwindow.h trianglevwindow.ui include/FittingInfo.h)

# 添加子目录
add_subdirectory(./TriangleSection)
add_subdirectory(./TriangleVSystem)

# 可执行文件
add_executable(${PROJECT_NAME} ${SRC_LIST})

## 添加子目录下的文件
# OpenCV
target_link_libraries(${PROJECT_NAME} ${Opencv_LIBS})
# TriangleSection
target_link_libraries(${PROJECT_NAME} TriangleDomainUtil TriangleDomainEntity)
target_link_libraries(${PROJECT_NAME} TriangleV)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
if (WIN32)
    set(DEBUG_SUFFIX)
    #    if (CMAKE_BUILD_TYPE MATCHES "Debug")
    #        set(DEBUG_SUFFIX "d")
    #    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
