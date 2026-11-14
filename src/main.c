#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "hal/hal.h"
#include "lvgl/lvgl.h"

#define SCREEN_HEIGHT 320
#define SCREEN_WIDTH 240

/* matching figma design for each object position */
#define LOGO_POS_X (SCREEN_WIDTH - 56 - 80)
#define LOGO_POS_Y (120)
#define TITLE_CN_POS_X (SCREEN_WIDTH - 136 - 20)
#define TITLE_CN_POS_Y (100)
#define TITLE_EN_POS_X (SCREEN_WIDTH - 165 - 16)
#define TITLE_EN_POS_Y (106)

LV_FONT_DECLARE(sourcehan_20);
LV_IMAGE_DECLARE(logo_solo_light);

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  lv_init();

  sdl_hal_init(240, 320);

  lv_obj_t *screen = lv_screen_active();
  lv_obj_set_style_bg_color(screen, lv_color_hex(0xFFFFFF), 0);

  lv_obj_t *logo = lv_image_create(screen);
  lv_image_set_src(logo, &logo_solo_light);
  lv_image_set_rotation(logo, 900);
  lv_obj_set_x(logo, LOGO_POS_X);
  lv_obj_set_y(logo, LOGO_POS_Y);

  lv_obj_t *title_cn = lv_label_create(screen);
  lv_label_set_text(title_cn, "赛灵森创意盒");
  lv_obj_set_style_text_font(title_cn, &sourcehan_20, 0);
  lv_obj_set_style_text_color(title_cn, lv_color_hex(0x000000), 0);
  lv_obj_set_style_transform_rotation(title_cn, 900, LV_PART_MAIN);
  lv_obj_set_x(title_cn, TITLE_CN_POS_X);
  lv_obj_set_y(title_cn, TITLE_CN_POS_Y);

  lv_obj_t *title_en = lv_label_create(screen);
  lv_label_set_text(title_en, "SensorSparks");
  lv_obj_set_style_text_font(title_en, &lv_font_montserrat_16, LV_PART_MAIN);
  lv_obj_set_style_text_color(title_en, lv_color_hex(0x000000), 0);
  lv_obj_set_style_transform_rotation(title_en, 900, LV_PART_MAIN);
  lv_obj_set_x(title_en, TITLE_EN_POS_X);
  lv_obj_set_y(title_en, TITLE_EN_POS_Y);

  lv_obj_update_layout(screen);

  printf("logo width: %d, label height: %d, x: %d, y: %d, pivot x: %d, pivot "
         "y: %d\n",
         lv_obj_get_width(logo), lv_obj_get_height(logo), lv_obj_get_x(logo),
         lv_obj_get_y(logo),
         lv_obj_get_style_transform_pivot_x(logo, LV_PART_MAIN),
         lv_obj_get_style_transform_pivot_y(logo, LV_PART_MAIN));
  printf("title_cn width: %d, title_cn height: %d, x: %d, y: %d, pivot x: %d, "
         "pivot y: "
         "%d\n",
         lv_obj_get_width(title_cn), lv_obj_get_height(title_cn),
         lv_obj_get_x(title_cn), lv_obj_get_y(title_cn),
         lv_obj_get_style_transform_pivot_x(title_cn, LV_PART_MAIN),
         lv_obj_get_style_transform_pivot_y(title_cn, LV_PART_MAIN));
  printf("title_en width: %d, title_en height: %d, x: %d, y: %d, pivot x: %d, "
         "pivot y: "
         "%d\n",
         lv_obj_get_width(title_en), lv_obj_get_height(title_en),
         lv_obj_get_x(title_en), lv_obj_get_y(title_en),
         lv_obj_get_style_transform_pivot_x(title_en, LV_PART_MAIN),
         lv_obj_get_style_transform_pivot_y(title_en, LV_PART_MAIN));

  lv_obj_t *position_screen = lv_obj_create(screen);
  lv_obj_set_size(position_screen, 5, 5);
  lv_obj_set_pos(position_screen, lv_obj_get_x(logo), lv_obj_get_y(logo));
  lv_obj_set_style_radius(position_screen, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_bg_color(position_screen, lv_color_hex(0xFF0000), 0);
  lv_obj_set_style_border_width(position_screen, 0, 0);

  lv_obj_t *position_title_cn = lv_obj_create(screen);
  lv_obj_set_size(position_title_cn, 5, 5);
  lv_obj_set_pos(position_title_cn, lv_obj_get_x(title_cn),
                 lv_obj_get_y(title_cn));
  lv_obj_set_style_radius(position_title_cn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_bg_color(position_title_cn, lv_color_hex(0x0000FF), 0);
  lv_obj_set_style_border_width(position_title_cn, 0, 0);

  while (1) {
    lv_timer_handler();
    usleep(5000);
  }

  return 0;
}
