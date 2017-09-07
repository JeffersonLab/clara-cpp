

set(command "/Applications/CLion.app/Contents/bin/cmake/bin/cmake;-GCodeBlocks - Unix Makefiles;/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-configure-out.log"
  ERROR_FILE "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "googlemock configure command succeeded.  See also /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-configure-*.log")
  message(STATUS "${msg}")
endif()
