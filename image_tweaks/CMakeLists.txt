


include(FetchContent)
FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  )
FetchContent_MakeAvailable(stb)


add_executable(image_tweaks main.cpp)


target_compile_features(image_tweaks PUBLIC cxx_std_20)
target_link_libraries(image_tweaks PRIVATE stb)


# include(CTest)
# enable_testing()


