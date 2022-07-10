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

#include "Board.hpp"

#define WIDTH 1200
#define HEIGHT WIDTH

void render(Board* board) {
    float squareSize = WIDTH / (float)board->getSize();
    for (int i = 0; i < board->getSize(); i++) {
        for (int j = 0; j < board->getSize(); j++) {
            // draws board
            ALLEGRO_COLOR color;
            // calculates black vs white square based on indices
            if ((i + j) % 2) {
                color = al_map_rgb(149, 110, 87); // brown (black)
            } else {
                color = al_map_rgb(220, 220, 198); // dark-ish beige (white)
            }
            
            Vec2f startLoc{
                (float)i * squareSize, (float)j * squareSize
            };
            al_draw_filled_rectangle(startLoc.x, startLoc.y, startLoc.x + squareSize, startLoc.y + squareSize, color);
            
            // draws pieces
            if (board->squares[i][j]) {
                // calculate center and radius of piece
                Vec2f center{
                    startLoc.x + squareSize / 2.0f, startLoc.y + squareSize / 2.0f
                };
                float radius = squareSize / 2.0f * 0.8f;
                
                ALLEGRO_COLOR pieceColor;
                if (board->squares[i][j]->getSide() == Player::WHITE) {
                    pieceColor = al_map_rgb(255, 255, 255);
                    al_draw_filled_circle(center.x, center.y, radius, pieceColor);
                } else {
                    pieceColor = al_map_rgb(0, 0, 0);
                    al_draw_filled_circle(center.x, center.y, radius, pieceColor);
                }
            }
        }
    }
}

int real_main(int argc, char** argv) {
    // create board
    Board* board = new Board();
    
    // init allegro5
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
    
    // game loop
    al_start_timer(timer);
    while (1) {
        al_wait_for_event(queue, &event);
        
        // handle events
        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        
        // renders board every frame
        if (redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            render(board);
            al_flip_display();
            
            redraw = false;
        }
    }
    
    // delete pointers
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    
    return 0;
}

int main(int argc, char** argv) {
    return al_run_main(argc, argv, real_main);
}
