set(SOURCES 
  operations.c
  player.c
  level.c
)

add_library(snake_lib ${SOURCES})
target_include_directories(snake_lib PUBLIC "${SnakeCS_SOURCE_DIR}/include")

add_executable(snake_cs main.c)
target_link_libraries(snake_cs PRIVATE snake_lib)