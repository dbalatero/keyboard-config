# keyboard-config

QMK keyboard configs

## Setup

Run `./qmk setup` after cloning the repo. Answer `Y` (yes) to all the prompts.

## Adding a new keymap

If you want to add a new keymap for a new keyboard:

1. Find the name of it, e.g. `handwired/dactyl_manuform/5x7` (you can look in `qmk_firmware/keyboards`)
2. `./qmk clone handwired/dactyl_manuform/5x7 dactyl_5x7`

You should now have a `dactyl_5x7` directory.

## Compiling and flashing your keymap

After editing the keymap you cloned with `./qmk clone`, compile your `.hex` file:

```
# replace "dactyl_5x7" with your map directory
$ ./qmk compile dactyl_5x7
```

To flash it onto your keyboard, plug it in and run:

```
$ ./qmk flash dactyl_5x7
```
