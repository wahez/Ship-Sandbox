
#
# ShipSandbox application
#

set  (SHIP_SANDBOX_SOURCES
	LoggingDialog.cpp
	LoggingDialog.h
	MainApp.cpp
	MainFrame.cpp
	MainFrame.h
	SettingsDialog.cpp
	SettingsDialog.h
	Version.h
	)

source_group(" " FILES ${SHIP_SANDBOX_SOURCES})

set  (RESOURCE_FILES
	Resources/ShipSandbox.rc
	Resources/Ship.ico)

source_group("Resources" FILES ${RESOURCE_FILES})

add_executable (ShipSandbox ${SHIP_SANDBOX_SOURCES} ${RESOURCE_FILES})

target_include_directories (ShipSandbox	PRIVATE	
	${WXWIDGETS_INCLUDE_DIRS})

target_link_libraries (ShipSandbox
	GameLib
	${OPENGL_LIBRARIES}
	debug ${WXWIDGETS_WXMSW_LIBRARY_DEBUG}
	optimized ${WXWIDGETS_WXMSW_LIBRARY_RELEASE}
	debug ${WXWIDGETS_WXBASE_LIBRARY_DEBUG}
	optimized ${WXWIDGETS_WXBASE_LIBRARY_RELEASE}
	${ADDITIONAL_LIBRARIES})

if (MSVC)
	set_target_properties(ShipSandbox PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /LTCG")
else (MSVC)
endif (MSVC)


#
# Set VS properties
#

if (MSVC)

	set (VS_STARTUP_PROJECT ShipSandbox)
	
	set_target_properties(
		ShipSandbox
		PROPERTIES
			# Set debugger working directory to binary output directory
			VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/$(Configuration)"

			# Set output directory to binary output directory - VS will add the configuration type
			RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	)

endif (MSVC)



#
# Copy files
#

message (STATUS "Copying data files and DevIL runtime files...")

file(COPY "${CMAKE_SOURCE_DIR}/Data"
	DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug")
file(COPY "${CMAKE_SOURCE_DIR}/Data"
	DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release")
file(COPY "${CMAKE_SOURCE_DIR}/Data"
	DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/RelWithDebInfo")

if (WIN32)
	file(COPY ${DEVIL_RUNTIME_LIBRARIES_DEBUG}
		DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug")
	file(COPY ${DEVIL_RUNTIME_LIBRARIES_RELEASE}
		DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release")
	file(COPY ${DEVIL_RUNTIME_LIBRARIES_RELEASE}
		DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/RelWithDebInfo")
endif (WIN32)
