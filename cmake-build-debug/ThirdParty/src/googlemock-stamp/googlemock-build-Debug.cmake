

set(command "${make}")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-build-out.log"
  ERROR_FILE "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "googlemock build command succeeded.  See also /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-build-*.log")
  message(STATUS "${msg}")
endif()
