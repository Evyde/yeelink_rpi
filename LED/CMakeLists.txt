set(LIB_SRC LED.c)
add_library(libLED ${LIB_SRC})
set_target_properties(libLED PROPERTIES OUTPUT_NAME "LED")
