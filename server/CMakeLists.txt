set(LIB_SRC server.c)
add_library(libserver ${LIB_SRC})
set_target_properties(libserver PROPERTIES OUTPUT_NAME "server")
