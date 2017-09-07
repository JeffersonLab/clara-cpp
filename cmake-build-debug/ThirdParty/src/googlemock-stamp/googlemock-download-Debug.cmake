

set(command "/Applications/CLion.app/Contents/bin/cmake/bin/cmake;-Dmake=${make};-Dconfig=${config};-P;/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-download-Debug-impl.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-download-out.log"
  ERROR_FILE "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "googlemock download command succeeded.  See also /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/googlemock-stamp/googlemock-download-*.log")
  message(STATUS "${msg}")
endif()
