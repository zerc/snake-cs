add_executable(snake_cs_check
  main.c
  check_operations.c
)

target_link_libraries(snake_cs_check check snake_lib)