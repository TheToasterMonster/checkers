//
//  main.cpp
//  Checkers
//
//  Created by Frank Qiang on 7/1/22.
//
#define ALLEGRO_NO_MAGIC_MAIN
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#define WIDTH 1500
#define HEIGHT WIDTH

int real_main(int argc, char** argv) {
    al_init();
    al_install_keyboard();
    
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(WIDTH, HEIGHT);
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    bool redraw = true;
    ALLEGRO_EVENT event;
    
    al_start_timer(timer);
    while (1) {
        al_wait_for_event(queue, &event);
        
        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        
        if (redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_filled_rectangle(0.0f, 0.0f, WIDTH / 2.0f, HEIGHT / 2.0f, al_map_rgb(255, 0, 0));
            al_flip_display();
            
            redraw = false;
        }
    }
    
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    
    return 0;
}

int main(int argc, char** argv) {
    return al_run_main(argc, argv, real_main);
}
