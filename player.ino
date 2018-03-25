
MovingBox player;


static const float gust_velocity = 0.5;
static const float gravity_velocity = 0.2;
static const float friction_velocity = 0.5;


static float headwind_velocity_x = 0.0;
static float headwind_velocity_y = 0.0;


void init_player() {

  // relative to screen size in order to facilitate port to classic
  player.w = gb.display.width() / 12;
  player.h = gb.display.height() / 6;

  // center initially
  player.x = (gb.display.width() / 2) - (player.w / 2);
  player.y = (gb.display.height() / 2) - (player.h / 2);

  // TODO: set initial headwind

  player.xv = 0;
  player.yv = 0;

}

void update_player() {
  
  // horizontal movement

  player.xv *= friction_velocity;

  // TODO: handle/update headwind

  if (gb.buttons.repeat(BUTTON_RIGHT, 1)) {
    player.xv += gust_velocity;
  }
  if (gb.buttons.repeat(BUTTON_LEFT, 1)) {
    player.xv -= gust_velocity;
  }
  
  // update
  player.x += player.xv;
  
  // check for collision with horizontalical bounds

  // left
  if (player.x <= 0) {
    player.x = 0;
    player.xv = 0;
  }
  
  // right
  if (player.x >= (gb.display.width() - player.w)) {
    player.x = (gb.display.width() - player.w);
    player.xv = 0;
  }
  

  // vertical movement

  player.yv += gravity_velocity;

  if (gb.buttons.repeat(BUTTON_UP, 1)) {
    player.yv -= gust_velocity;
  }
  
  // update
  player.y += player.yv;

  // check for collision with vertical bounds

  // ceiling
  if (player.y <= 0) {
    player.y = 0;
    player.yv = 0;
  }
  
  // floor
  if (player.y >= (gb.display.height() - player.h)) {
    player.y = (gb.display.height() - player.h);
    player.yv = 0;
  }
  
}

void draw_player() {

  // TODO: replace with kite shape
  gb.display.fillRect(player.x, player.y, player.w, player.h);

}

