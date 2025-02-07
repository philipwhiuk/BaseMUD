# Changelog for BaseMUD

## Version 0.0.3 (2019-10-03)

**Project Organization:**

* Reorganized 'Internal Changes' section in README.md to:
    - Deployment
    - Code Reorganization
    - Code Reduction
    - Code Changes
* Reorganized 'Gameplay Changes' section (now 'Game Changes') in README.md to:
    - Bugfixes
    - Patched oversights
    - Quality-of-Life features
    - Gameplay Changes
    - Optional Features
* Many of the "TO-DO's" have been moved to a Trello board for better tracking.

**Bugfixes:**

* When wearing an item, _all_ potential slots are now checked, not just related
  slots (e.g, a ring can now be held as well as worn on a finger).
* In most cases, finding characters and objects by '1.thing', '2.thing', etc.
  will now count correctly when searching multiple locations (e.g, check the room,
  then the rest of the world). This is done by a `find_continue_count()` call
  preceding the next check.
* Checks for immune/resistant/vulnerable flags completely ignored default
  weapon/magic imm/res/vuln flags, despite existing code with implied behavior.
  Resistance no longer overrides default immunity, and vulnerability now
  properly _downgrades_ the default status (imm`->`res, res`->`normal,
  normal`->`vuln).

**Internal Changes:**

* Separated mob- and player-specific flags (`ACT_*`) into separate `MOB_*` and `PLR_*`
  flags, with separate variables. This should prevent a _lot_ of bugs.
* The `wear` command now uses a table for looking up wear slots, as does `char_wear_obj()`.
  This is a big improvement from copy+pasted "You wear ___ on ___" code for each possible slot.
* Weather change calculations have been made easier to understand (but could still be better).
* Replaced `is_safe()` and `is_safe_spell()` with consolidated
    `do_filter_can_attack_real()`. Added shorter functions:
    `do_filter_can_attack()`, `do_filter_can_attack_spell()`,
    `can_attack()`, and `can_attack_spell()`.
* Merged `db2.c` into `db.c` and separated old database functions into `db_old.c`.
* Merged code for displaying exits in `look`, `exits`, and exits in the prompt.
* Introduced `dam_type` classes `DAM_PHYSICAL` and `DAM_MAGICAL` for determining
  immunity.
* Separated descriptor functions in `comm.c` into new file `descs.c`.
* Moved some game loop functions from `comm.c` to `main.c`.
* Several miscellaneous clean-ups for redundant or deprecated code.

# Changelog for BaseMUD

## Version 0.0.2 (2019-08-31)

- Added the entire world as a sample JSON file (`json/everything.json`).
- Reviewed some immortal commands, re-added `addapply` oedit command, changed `vector` and `bitvector` to `bits` for consistency
- Implementors no longer have to suffer wait/daze lag. Fixed "heat metal" to abort if a save is SUCCESSFUL, not the opposite.
- Vanilla open exits no longer show "-" mark when doors are open. Without `#define VANILLA`, dash marks are still present.
- Removed `Dockerfile` until it's updated properly.
- Refactored most of the "wiz" commands.
- Moved "day of the week" and "months of the year" to a table in `tables.c`.
- Weather and sun position now use a table.
- Weather change calculations have been made easier to understand (but could still be better).
- Modified `stand` command to let you stand at/on/in different objects (or no object) when already standing. Likewise, typing `stand` without an argument while standing at/on/in something will step off/out of them.
- Lots of refactoring to 'find_()' methods. Maybe have been renamed for consistency and clarity.
- Added `find_door_same_room()` so you can type things like `open 2.door`.
