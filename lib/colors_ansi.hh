#ifndef COLORS_H
#define COLORS_H

namespace colors {
    inline constexpr char reset[]      = "\u001b[0m";

    inline namespace effects {
        inline constexpr char bold[]       = "\u001b[1m";
        inline constexpr char dim[]        = "\u001b[2m";
        inline constexpr char italic[]     = "\u001b[3m";
        inline constexpr char underline[]  = "\u001b[4m";
        inline constexpr char blink[]      = "\u001b[5m";
        inline constexpr char reverse[]    = "\u001b[7m";
        inline constexpr char hidden[]     = "\u001b[8m";
    }

    inline namespace fg16 {
        inline constexpr char red[]        = "\u001b[91m";
        inline constexpr char green[]      = "\u001b[92m";
        inline constexpr char yellow[]     = "\u001b[93m";
        inline constexpr char blue[]       = "\u001b[94m";
        inline constexpr char magenta[]    = "\u001b[95m";
        inline constexpr char cyan[]       = "\u001b[96m";
        inline constexpr char white[]      = "\u001b[97m";
        inline constexpr char black[]      = "\u001b[30m";
    }

    inline namespace fg256 {
        inline constexpr char black[]   = "\x1b[38;5;0m";
        inline constexpr char maroon[]  = "\x1b[38;5;1m";
        inline constexpr char green[]   = "\x1b[38;5;2m";
        inline constexpr char olive[]   = "\x1b[38;5;3m";
        inline constexpr char navy[]    = "\x1b[38;5;4m";
        inline constexpr char purple[]  = "\x1b[38;5;5m";
        inline constexpr char teal[]    = "\x1b[38;5;6m";
        inline constexpr char silver[]  = "\x1b[38;5;7m";
        inline constexpr char grey[]    = "\x1b[38;5;8m";
        inline constexpr char red[]     = "\x1b[38;5;9m";
        inline constexpr char lime[]    = "\x1b[38;5;10m";
        inline constexpr char yellow[]  = "\x1b[38;5;11m";
        inline constexpr char blue[]    = "\x1b[38;5;12m";
        inline constexpr char fuchsia[] = "\x1b[38;5;13m";
        inline constexpr char aqua[]    = "\x1b[38;5;14m";
        inline constexpr char white[]   = "\x1b[38;5;15m";
        inline constexpr char grey0[]   = "\x1b[38;5;16m";
        inline constexpr char grey1[]   = "\x1b[38;5;232m";
        inline constexpr char grey2[]   = "\x1b[38;5;233m";
        inline constexpr char grey3[]   = "\x1b[38;5;234m";
        inline constexpr char grey4[]   = "\x1b[38;5;235m";
        inline constexpr char grey5[]   = "\x1b[38;5;236m";
    }

    inline namespace bg256 {
        inline constexpr char black[]   = "\x1b[48;5;0m";
        inline constexpr char maroon[]  = "\x1b[48;5;1m";
        inline constexpr char green[]   = "\x1b[48;5;2m";
        inline constexpr char olive[]   = "\x1b[48;5;3m";
        inline constexpr char navy[]    = "\x1b[48;5;4m";
        inline constexpr char purple[]  = "\x1b[48;5;5m";
        inline constexpr char teal[]    = "\x1b[48;5;6m";
        inline constexpr char silver[]  = "\x1b[48;5;7m";
        inline constexpr char grey[]    = "\x1b[48;5;8m";
        inline constexpr char red[]     = "\x1b[48;5;9m";
        inline constexpr char lime[]    = "\x1b[48;5;10m";
        inline constexpr char yellow[]  = "\x1b[48;5;11m";
        inline constexpr char blue[]    = "\x1b[48;5;12m";
        inline constexpr char fuchsia[] = "\x1b[48;5;13m";
        inline constexpr char aqua[]    = "\x1b[48;5;14m";
        inline constexpr char white[]   = "\x1b[48;5;15m";
        inline constexpr char grey0[]   = "\x1b[48;5;16m";
        inline constexpr char grey1[]   = "\x1b[48;5;232m";
        inline constexpr char grey2[]   = "\x1b[48;5;233m";
        inline constexpr char grey3[]   = "\x1b[48;5;234m";
        inline constexpr char grey4[]   = "\x1b[48;5;235m";
        inline constexpr char grey5[]   = "\x1b[48;5;236m";
    }
}

#endif // COLORS_H
