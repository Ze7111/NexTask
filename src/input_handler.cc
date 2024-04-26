#include <conio.h>
#include <iostream>
#include <string>
#include "../lib/colors_ansi.hh"
#include "../lib/custom_stl.hh"
#include "../lib/debug_utils.hh"

struct timeinf {
    int tm_hour;
    int tm_min;
};

inline void inc_hour(timeinf *time, std::string &denoted) {
    time->tm_hour++;
    if (time->tm_hour > 12) {
        time->tm_hour = 1;
        denoted = denoted == "am" ? "pm" : "am";
    }
}

inline void dec_hour(timeinf *time, std::string &denoted) {
    time->tm_hour--;
    if (time->tm_hour < 1) {
        time->tm_hour = 12;
        denoted = denoted == "am" ? "pm" : "am";
    }
}

inline void inc_min(timeinf *time, std::string &denoted) {
    time->tm_min++;
    if (time->tm_min > 59) {
        time->tm_min = 0;
        inc_hour(time, denoted);
    }
}

inline void dec_min(timeinf *time, std::string &denoted) {
    time->tm_min--;
    if (time->tm_min < 0) {
        time->tm_min = 59;
        dec_hour(time, denoted);
    }
}

void generate_fmt_time(std::string &fmt_time, timeinf *time, std::string denoted, int cur_sel) {
    fmt_time = colors::reset
        + (cur_sel == 0
        ? std::string(colors::fg256::red) + std::string(colors::effects::blink)
        : std::string(colors::fg256::yellow))
        + (time->tm_hour < 10
        ? "0" + std::to_string(time->tm_hour)
        : std::to_string(time->tm_hour))
        + colors::reset
        + ":"
        + colors::reset
        + (cur_sel == 1
        ? std::string(colors::fg256::red) + std::string(colors::effects::blink)
        : std::string(colors::fg256::yellow))
        + (time->tm_min < 10
        ? "0" + std::to_string(time->tm_min)
        : std::to_string(time->tm_min))
        + colors::reset
        + " "
        + (denoted == "am"
        ? std::string(colors::fg256::green)
        : std::string(colors::fg16::yellow))
        + denoted
        + colors::reset;
}

template <typename... Args>
inline void print_o2ic(Args &&...args) {
    std_v2::print("\x1b[1A", std_v2::sysIO::endl(""));
    std_v2::print("\x1b[2K", std_v2::sysIO::endl(""));

    std_v2::print(std::forward<Args>(args)...);
}

namespace keys {
    const int KEY_ARROW = 224;
    const int KEY_L_ARROW = 75;
    const int KEY_R_ARROW = 77;
    const int KEY_U_ARROW = 72;
    const int KEY_D_ARROW = 80;
    const int KEY_ENTER = 13;
    const int SEQ_CTRL_C = 3;
}

int main() {
    // Infinite loop to continuously wait for input
    auto *test = new timeinf{12, 0};
    std::string denoted = "am";
    int current = 0;  // 0 = hour, 1 = minute
    std::string formatted_time = "";

    std_v2::print();

    while (true) {
        generate_fmt_time(formatted_time, test, denoted, current);
        print_o2ic("Selected Time: ", formatted_time);

        int key = _getch();
        if (key == keys::KEY_ARROW) {
            switch (_getch()) {
            case keys::KEY_L_ARROW:  // Left arrow
                dec_hour(test, denoted);
                current = 0;
                break;
            case keys::KEY_R_ARROW:  // Right arrow
                inc_hour(test, denoted);
                current = 0;
                break;
            case keys::KEY_U_ARROW:  // Up arrow
                inc_min(test, denoted);
                current = 1;
                break;
            case keys::KEY_D_ARROW:  // Down arrow
                dec_min(test, denoted);
                current = 1;
                break;
            default:
                continue;
            }
        } else if /* Enter key */ (key == 13) {
            generate_fmt_time(formatted_time, test, denoted, 3);
            print_o2ic("Selected Time: ", formatted_time);
            break;
        } else if /* ctrl+c */ (key == 3) {
            break;
        }
    }
    delete test;
    return 0;
}