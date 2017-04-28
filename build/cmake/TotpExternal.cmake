#################################################
# TOTP lib
#################################################

add_subdirectory(${SAMP_TOTP_EXTERNAL}/totp)

##################################################
# AMXLib / sampsdk
##################################################
SET(SAMPSDK_PATH ${SAMP_TOTP_EXTERNAL}/sampsdk)
set(SAMPSDK_INCLUDE_DIR ${SAMPSDK_PATH})

# Definitions
add_definitions(-DSAMPSDK_INCLUDE_DIR=${SAMPSDK_INCLUDE_DIR})
add_definitions(-DSAMPSDK_DIR=${SAMPSDK_PATH})

add_library(sampsdk 
	${SAMPSDK_PATH}/amxplugin.cpp
	${SAMPSDK_PATH}/plugin.h
	${SAMPSDK_PATH}/plugincommon.h
)

target_include_directories(sampsdk PUBLIC ${SAMPSDK_INCLUDE_DIR})
if (WIN32)
	target_compile_definitions(sampsdk PRIVATE WIN32)
else()
	target_include_directories(sampsdk PUBLIC ${SAMPSDK_INCLUDE_DIR}/amx)
	target_compile_definitions(sampsdk PRIVATE LINUX)
endif()

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set_property(TARGET sampsdk APPEND_STRING PROPERTY COMPILE_FLAGS " -m32")
	set_property(TARGET sampsdk APPEND_STRING PROPERTY LINK_FLAGS    " -m32")
endif()