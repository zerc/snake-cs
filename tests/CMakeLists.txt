add_executable(snake_cs_check
  main.c
  check_operations.c
  check_player.c
)

target_link_libraries(snake_cs_check check snake_lib)
add_test(NAME snake_check COMMAND snake_cs_check)