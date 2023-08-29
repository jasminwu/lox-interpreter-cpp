#include "color/colormod.hpp"

// foreground colors
auto static red_f = Color::Modifier(Color::FG_RED);
auto static green_f = Color::Modifier(Color::FG_GREEN);
auto static blue_f = Color::Modifier(Color::FG_BLUE);
auto static white_f = Color::Modifier(Color::FG_DEFAULT);
auto static lgray_f = Color::Modifier(Color::FG_LIGHT_GRAY);
auto static dgray_f = Color::Modifier(Color::FG_DARK_GRAY);
auto static yellow_f = Color::Modifier(Color::FG_YELLOW);
auto static mag_f = Color::Modifier(Color::FG_MAGENTA);
auto static cyan_f = Color::Modifier(Color::FG_CYAN);
auto static lgreen_f = Color::Modifier(Color::FG_LIGHT_GREEN);

// background colors
auto static red_b = Color::Modifier(Color::BG_RED);
auto static green_b = Color::Modifier(Color::BG_GREEN);
auto static blue_b = Color::Modifier(Color::BG_BLUE);
auto static default_b = Color::Modifier(Color::BG_DEFAULT);
auto static dgray_b = Color::Modifier(Color::BG_DARK_GRAY);

// other formatting
auto static reset = Color::Modifier(Color::RESET);
auto static bold = Color::Modifier(Color::BOLD);
auto static ul = Color::Modifier(Color::UNDERLINE);
auto static dim = Color::Modifier(Color::DIM);
auto static blink = Color::Modifier(Color::BLINK);
