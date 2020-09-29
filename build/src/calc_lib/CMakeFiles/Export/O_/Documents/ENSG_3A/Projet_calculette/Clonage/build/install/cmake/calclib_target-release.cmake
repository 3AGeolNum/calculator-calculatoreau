#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "calclib" for configuration "Release"
set_property(TARGET calclib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(calclib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "O:/Documents/ENSG_3A/Projet_calculette/Clonage/build/install/lib/calclib.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS calclib )
list(APPEND _IMPORT_CHECK_FILES_FOR_calclib "O:/Documents/ENSG_3A/Projet_calculette/Clonage/build/install/lib/calclib.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
