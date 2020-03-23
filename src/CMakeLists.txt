
add_executable(ssd)

set_target_properties(ssd
    PROPERTIES
        DEBUG_POSTFIX d
)

target_sources(ssd
    PRIVATE
        main.cpp
)

target_compile_features(ssd PRIVATE cxx_std_17)

target_compile_options(ssd
    PRIVATE
        $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<COMPILE_LANGUAGE:CXX>>:/D _AFXDLL>
        $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<COMPILE_LANGUAGE:CXX>>:/permissive- /W4 /WX /Zc:__cplusplus>
        $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<COMPILE_LANGUAGE:CXX>>:/experimental:external /external:W0 /external:templates->
        $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<COMPILE_LANGUAGE:CXX>>:/external:anglebrackets>
)

#target_link_libraries(ssd PRIVATE bfg_lyra)  # user32.dll ??


# Install
include(GNUInstallDirs)

install(TARGETS ssd
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)

