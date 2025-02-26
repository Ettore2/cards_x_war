cmake_minimum_required(VERSION 3.28)
project(cards_e_war C)

set(CMAKE_C_STANDARD 11)

add_executable(cards_e_war
        c_x_w_cards.c
        c_x_w_field_objects.c
        c_x_w_map_events.c
        c_x_w_potions.c
        c_x_w_relics.c
        cards_x_war_game.c
        genericList.c
        list_test.c
        main.c)
