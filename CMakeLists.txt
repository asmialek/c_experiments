# compiler flags
set(CFLAGS "-O2 -std=gnu17 -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CFLAGS}")

# linker flags
set(LDFLAGS "-lrt -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${LDFLAGS}")


add_executable(priority_queue priority_queue.c)
add_executable(pointers pointers.c)
add_executable(queue queue.c)
add_executable(struct struct.c)
add_executable(mutexes mutexes.c)
add_executable(arrays arrays.c)