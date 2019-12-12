#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using n_t = std::uint64_t ;
using s_t = std::int64_t ;

constexpr n_t height = 18;
constexpr n_t width  = 32;
using screen_t = std::array<std::uint8_t, height * width>;
constexpr std::array<char, 32> char_map {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                                         'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'};
template <typename T>
constexpr T transform(T x, T y){
  return y * height + x;
}
std::ostream &operator<<(std::ostream &strm, const screen_t &screen){
  for (n_t y = 0; y < height; ++y){
    for (n_t x = 0; x < width; ++x) strm << char_map[screen[y * width + x]];
    strm << std::endl;
  }
  return strm;
}

void illuminate(screen_t &screen, n_t x_l, n_t y_l){
  screen[transform(x_l, y_l)] = 0xFF;
  constexpr s_t max_d = 10;
  for (s_t d = 1; d < max_d; ++d){
    for (s_t a = -d; a < d; ++a){
      // (+d, a)(-d, a)(a, +d)(a, -d)
      s_t v = [](double d, double a) -> s_t {
        if (a/d < -0.5) return -1;
        else if (a/d > 0.5) return 1;
        else return 0;
      }(d, a);
      constexpr static auto ill = [&](s_t dir) {

      };
    }
  }
  /*for (n_t y = height; y-- > 0;) {
    for (n_t x = width; x-- > 0;) {
      double x_d = static_cast<s_t>(x_l) - static_cast<s_t>(x);
      double y_d = static_cast<s_t>(y_l) - static_cast<s_t>(y);
      auto d = std::hypot(x_d, y_d);
      screen[y * width + x] = d;
    }
  }*/
}

int main() {
  screen_t screen{};
  illuminate(screen, width/2, height/2);
  std::cout << screen;
  return 0;
}
