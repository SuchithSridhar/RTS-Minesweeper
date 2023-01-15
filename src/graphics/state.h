#ifndef STATE_H
#define STATE_H

/*
 * These are arbitrary integers and can be changed without problems.
 * However, each state much have a unique number.
 */

#define STATE_START 0
#define STATE_START_SETTINGS 1

// State used to initialize gameplay 
#define STATE_TRANSITION_GAMEPLAY 2

#define STATE_GAMEPLAY 3
#define STATE_SETTINGS 4
#define STATE_STATISTICS 5
#define STATE_EXIT 6

#endif
