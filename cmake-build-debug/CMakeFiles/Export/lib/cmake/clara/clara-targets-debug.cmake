#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Clara::clara" for configuration "Debug"
set_property(TARGET Clara::clara APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Clara::clara PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libclara.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libclara.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS Clara::clara )
list(APPEND _IMPORT_CHECK_FILES_FOR_Clara::clara "${_IMPORT_PREFIX}/lib/libclara.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
