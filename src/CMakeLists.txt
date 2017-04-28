include(AMXConfig)
include(AddSAMPPlugin)

# Create dummy target that does nothing
add_custom_target(totplib_deps)

set(SOURCE_FILES
	Logprintf.cpp
	Natives.cpp
	Plugin.cpp
)

SET(HEADER_FILES
	Logprintf.hpp
	Config.hpp
	Natives.hpp
)

# Plugin
add_samp_plugin(totplib
  ${SOURCE_FILES}
  ${HEADER_FILES}
  Plugin.def
)

# SPDLog Include file handling
set(TOTP_INCLUDE_SRC "${SAMP_TOTP_ROOT}/include/a_totp.inc")
set(TOTP_INCLUDE_DST "${SAMP_TOTP_BIN_OUT_DIR}/include/a_totp.inc")

add_custom_command(
        TARGET  totplib_deps POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${TOTP_INCLUDE_SRC}
                ${TOTP_INCLUDE_DST}
		COMMENT "Copy Pawno include file")

# Deps
add_dependencies(totplib totplib_deps)
		
# Link
target_link_libraries(totplib sampsdk cppotp)

# Includes
target_include_directories(totplib PRIVATE ${SAMP_TOTP_BIN_ROOT})

# Properties
set_target_properties(totplib PROPERTIES OUTPUT_NAME "totp")

# Target output
set_target_properties(totplib
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${SAMP_TOTP_BIN_OUT_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${SAMP_TOTP_BIN_OUT_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${SAMP_TOTP_BIN_OUT_DIR}"
)
