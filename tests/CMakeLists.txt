add_executable(snake_cs_check
  main.c
  check_vector.c
  check_level.c
  check_matrix.c
  check_options.c
)

target_link_libraries(snake_cs_check check snake_lib)
add_test(NAME snake_check COMMAND snake_cs_check)