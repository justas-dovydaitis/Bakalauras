#ifndef BT_COMMAND_H
#define BT_COMMAND_H

typedef enum
{
    IGNITION = 0,
    IGNITION_OFF,
    STARTER,
    STARTER_OFF,
    LEFT_TURN,
    RIGHT_TURN,
    TURNS_OFF,
    HAZARD,
    HEADLIGHT,
    HEADLIGHT_OFF,
    HIGH_BEAM,
    HIGH_BEAM_OFF,
    MARKERS,
    MARKERS_OFF,
    HORN,
    HORN_OFF
} BTCommand;

extern BTCommand cmd;

#endif