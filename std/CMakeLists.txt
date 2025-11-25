add_library(std STATIC cli.c error.c io.c memory.c strings.c)

target_include_directories(std PRIVATE "../include/")
