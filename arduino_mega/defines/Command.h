#ifndef COMMAND_H
#define COMMAND_H

typedef enum
{
    IGNITION = 1,
    IGNITION_OFF = 2,
    STARTER = 3,
    STARTER_OFF = 4,
    LEFT_TURN = 5,
    RIGHT_TURN = 6,
    TURNS_OFF = 7,
    HAZARD = 8,
    HEADLIGHT = 9,
    HEADLIGHT_OFF = 10,
    HIGH_BEAM = 11,
    HIGH_BEAM_OFF = 12,
    MARKERS = 13,
    MARKERS_OFF = 14,
    HORN = 15,
    HORN_OFF = 16,
    LOCK = 17
} Command;

extern Command cmd;

#endif