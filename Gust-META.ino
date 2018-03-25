#include <Gamebuino-Meta.h>


typedef struct {
  byte w;
  float x;
  float xv;
  byte h;
  float y;
  float yv;
} MovingBox;


void setup() {

  gb.begin();

  init_game();
  
}

void loop() {
  
  while(!gb.update());
  
  gb.display.clear();

  update_player();

  draw_player();

  gb.display.cursorX = gb.display.height() * (1.0 / 16.0);
  gb.display.cursorY = gb.display.height() * (7.0 / 8.0);
  gb.display.setColor(DARKGRAY);
  gb.display.print(F("CPU:"));
  gb.display.print(gb.getCpuLoad());
  gb.display.print(F("% "));
  gb.display.print(F("RAM:"));
  gb.display.println(gb.getFreeRam());
  
}

void init_game() {
  
  init_player();
  
}

