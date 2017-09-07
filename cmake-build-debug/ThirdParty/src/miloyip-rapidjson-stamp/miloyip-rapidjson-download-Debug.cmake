

set(command "/Applications/CLion.app/Contents/bin/cmake/bin/cmake;-Dmake=${make};-Dconfig=${config};-P;/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/miloyip-rapidjson-stamp/miloyip-rapidjson-download-Debug-impl.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/miloyip-rapidjson-stamp/miloyip-rapidjson-download-out.log"
  ERROR_FILE "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/miloyip-rapidjson-stamp/miloyip-rapidjson-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/miloyip-rapidjson-stamp/miloyip-rapidjson-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "miloyip-rapidjson download command succeeded.  See also /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/ThirdParty/src/miloyip-rapidjson-stamp/miloyip-rapidjson-download-*.log")
  message(STATUS "${msg}")
endif()
