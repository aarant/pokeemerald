# Pokémon Emerald

This is a decompilation of Pokémon Emerald.

It builds the following ROM:

* [**pokeemerald.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=1961) `sha1: f3ae088181bf583e55daf962a92bb46f4f1d07b7`

**guillotine** branch:
* ~~Decapitates~~ Decapitalizes text at compile-time, with some exceptions (see the [FAQ](#guillotine-q-how-can-i-keep-my-strings-from-being-decapped))
* Future-proof, doesn't require mass-replacing strings

To set up the repository, see [INSTALL.md](INSTALL.md).

## FAQ
### `(guillotine)` Q: How can I keep my string(s) from being decapped?
A: There are a number of ways to make a string "fixed case" so that it will not be decapitalized when displayed:

C strings: Replace the `_` with `_C`:
```c
// _C = fixed (C)ase string!
const u8 gText_IDNumber[] = _C("IDNo.");
```
ASM strings: Replace `.string` with `.fixstr`:
```arm
gText_SavingDontTurnOff::
    @ Lasts until the end of the line
	.fixstr "SAVING…\n"
	.fixstr "DON'T TURN OFF THE POWER.$"
```
You can fix-case/unfix parts of a string like so:
```arm
	.string "{FIXED_CASE}WARNING!{UNFIX_CASE}\p"
```
See also the configuration in [decap_config.h](include/constants/decap_config.h).

There's also special handling for "separated bigrams"; basically, two letter words.
This includes: `"TM01", "PC", "ID"`, any two uppercase characters surrounded by (generally) non-alphabetic characters. These will have their case preserved.

Character attributes are defined in tables in [charmap.cpp](tools/preproc/charmap.cpp) and [charmap.h](tools/preproc/charmap.h).

## See also

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).
