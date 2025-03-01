#ifndef GUARD_CONSTANTS_DECAP_CONFIG_H
#define GUARD_CONSTANTS_DECAP_CONFIG_H

// Configuration for Guillotine,
// the compile-time/preproc decapitalization system.

// Note: When changing these settings, you may have to
// `make clean` in order for them to take effect;
// strings usually have to be re-processed by preproc.

// Note: Because this file is used by preproc,
// we use 1 and 0 instead of TRUE and FALSE,
// which might not be defined there.

/*
Enable automatic decapitalization of all static text
Exceptions:
- Separated bigrams: "TM01", " PC ", " EV ", etc.
- Dynamic text content: player names, nicknames, box names
- Strings beginning with {FIXED_CASE}:
  - C strings that use `_C` or `__C`
  - ASM strings that use `.fixstr`

Note: If using poryscript, see the README for an argument
      to pass for better compatibility with this + formatted strings
*/
#define DECAP_ENABLED       1

// If TRUE, *default* player names will be decapitalized.
// Otherwise, their case will be preserved.
#define DECAP_PLAYER_NAMES  1

#define DECAP_SPECIES_NAMES 1
#define DECAP_MOVE_NAMES    1
#define DECAP_ITEMS         1 // Names & descriptions

#define DECAP_MAIN_MENU     1 // Main menu options
#define DECAP_OPTION_MENU   1 // Option menu texts
#define DECAP_START_MENU    1 // Start menu options/save menu text
#define DECAP_PARTY_MENU    1 // Party menu texts
#define DECAP_MAP_NAMES     1 // Map/location names
#define DECAP_EASY_CHAT     1 // Both words and interface
#define DECAP_FIELD_MSG     1 // Scripts (anything using `.string`)
#define DECAP_SUMMARY       1 // Summary interface

#endif // GUARD_CONSTANTS_DECAP_CONFIG_H
