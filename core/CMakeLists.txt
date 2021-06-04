set(PROJECT_NAME smartgl-core)

################################################################################
# Source groups
################################################################################
set(src__sfllhkhan95.smartgl
    "src/sfllhkhan95/smartgl/AppWindow.cpp"
    "src/sfllhkhan95/smartgl/AppWindow.h"
    "src/sfllhkhan95/smartgl/ContentFit.h"
    "src/sfllhkhan95/smartgl/globals.h"
    "src/sfllhkhan95/smartgl/SmartGLApp.cpp"
    "src/sfllhkhan95/smartgl/SmartGLApp.h"
    "src/sfllhkhan95/smartgl/stdafx.cpp"
    "src/sfllhkhan95/smartgl/stdafx.h"
    "src/sfllhkhan95/smartgl/targetver.h"
)
source_group("src\\sfllhkhan95.smartgl" FILES ${src__sfllhkhan95.smartgl})

set(src__sfllhkhan95.smartgl__io
    "src/sfllhkhan95/smartgl/io/Callbacks.cpp"
    "src/sfllhkhan95/smartgl/io/Callbacks.h"
    "src/sfllhkhan95/smartgl/io/KeyboardListener.cpp"
    "src/sfllhkhan95/smartgl/io/KeyboardListener.h"
    "src/sfllhkhan95/smartgl/io/MouseListener.cpp"
    "src/sfllhkhan95/smartgl/io/MouseListener.h"
)
source_group("src\\sfllhkhan95.smartgl\\io" FILES ${src__sfllhkhan95.smartgl__io})

set(src__sfllhkhan95.smartgl__ui
    "src/sfllhkhan95/smartgl/ui/Activity.cpp"
    "src/sfllhkhan95/smartgl/ui/Activity.h"
    "src/sfllhkhan95/smartgl/ui/ActivityManager.cpp"
    "src/sfllhkhan95/smartgl/ui/ActivityManager.h"
    "src/sfllhkhan95/smartgl/ui/Colors.h"
    "src/sfllhkhan95/smartgl/ui/Drawable.cpp"
    "src/sfllhkhan95/smartgl/ui/Drawable.h"
    "src/sfllhkhan95/smartgl/ui/Transformable.cpp"
    "src/sfllhkhan95/smartgl/ui/Transformable.h"
)
source_group("src\\sfllhkhan95.smartgl\\ui" FILES ${src__sfllhkhan95.smartgl__ui})

set(src__sfllhkhan95.smartgl__ui__shape
    "src/sfllhkhan95/smartgl/ui/shape/Circle.cpp"
    "src/sfllhkhan95/smartgl/ui/shape/Circle.h"
    "src/sfllhkhan95/smartgl/ui/shape/Line.cpp"
    "src/sfllhkhan95/smartgl/ui/shape/Line.h"
    "src/sfllhkhan95/smartgl/ui/shape/Point.cpp"
    "src/sfllhkhan95/smartgl/ui/shape/Point.h"
    "src/sfllhkhan95/smartgl/ui/shape/Rectangle.cpp"
    "src/sfllhkhan95/smartgl/ui/shape/Rectangle.h"
    "src/sfllhkhan95/smartgl/ui/shape/RoundedRectangle.cpp"
    "src/sfllhkhan95/smartgl/ui/shape/RoundedRectangle.h"
    "src/sfllhkhan95/smartgl/ui/shape/Shape.h"
    "src/sfllhkhan95/smartgl/ui/shape/Square.cpp"
    "src/sfllhkhan95/smartgl/ui/shape/Square.h"
    "src/sfllhkhan95/smartgl/ui/shape/Triangle.cpp"
    "src/sfllhkhan95/smartgl/ui/shape/Triangle.h"
)
source_group("src\\sfllhkhan95.smartgl\\ui\\shape" FILES ${src__sfllhkhan95.smartgl__ui__shape})

set(src__sfllhkhan95.smartgl__ui__view
    "src/sfllhkhan95/smartgl/ui/view/Animation.cpp"
    "src/sfllhkhan95/smartgl/ui/view/Animation.h"
    "src/sfllhkhan95/smartgl/ui/view/Button.cpp"
    "src/sfllhkhan95/smartgl/ui/view/Button.h"
    "src/sfllhkhan95/smartgl/ui/view/EditText.h"
    "src/sfllhkhan95/smartgl/ui/view/ImageView.cpp"
    "src/sfllhkhan95/smartgl/ui/view/ImageView.h"
    "src/sfllhkhan95/smartgl/ui/view/TextView.cpp"
    "src/sfllhkhan95/smartgl/ui/view/TextView.h"
    "src/sfllhkhan95/smartgl/ui/view/View.cpp"
    "src/sfllhkhan95/smartgl/ui/view/View.h"
)
source_group("src\\sfllhkhan95.smartgl\\ui\\view" FILES ${src__sfllhkhan95.smartgl__ui__view})

set(ALL_FILES
    ${src__sfllhkhan95.smartgl}
    ${src__sfllhkhan95.smartgl__io}
    ${src__sfllhkhan95.smartgl__ui}
    ${src__sfllhkhan95.smartgl__ui__shape}
    ${src__sfllhkhan95.smartgl__ui__view}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

add_precompiled_header(${PROJECT_NAME} "stdafx.h" "src/sfllhkhan95/smartgl/stdafx.cpp")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE SmartGLGraphicsLibrary)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG   "smartgl"
    TARGET_NAME_RELEASE "sglut"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}//build/"
    OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}//libs/"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Users/saifkhichi96/dev/personal/smartgl/sources/windows/libs/include;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/sfllhkhan95/smartgl"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG"
    ">"
    "WIN32;"
    "_LIB;"
    "UNICODE;"
    "_UNICODE"
)

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /Od
        >
        $<$<CONFIG:Release>:
            /O2;
            /Oi;
            /Gy
        >
        /W3;
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:
            /OPT:REF;
            /OPT:ICF
        >
        /SUBSYSTEM:WINDOWS
    )
endif()

target_link_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_SOURCE_DIR}//libs/"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_SOURCE_DIR}//libs"
    ">"
)

