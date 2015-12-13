file(GLOB SOURCES *.c*)
file(GLOB HEADERS *.h)

if(${ARCH} STREQUAL "x86")
	set(ARCHFLAGS "-melf_i386 -T kernel.ld")
	set(CMAKE_C_FLAGS "-m32 -Wall -g -fstack-protector-all -nostdinc")
	set(CMAKE_CXX_FLAGS "-m32 -Wall -g -fstack-protector-all -nostdinc -fno-builtin -fno-use-cxa-atexit")
endif()

include_directories("include" "../libdayos/include" "../libmath" ${DAYOS_KERNEL_INCLUDE})
add_library(stdc++ STATIC ${SOURCES} ${HEADERS})

## UUUUGLY!
install(TARGETS stdc++ DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/lib")
install(FILES ${HEADERS} DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include")