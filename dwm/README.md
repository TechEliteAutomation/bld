# DWM - Solarized Configuration

## Overview

This is a customized build of dwm (dynamic window manager) with the following specifications:

- Base: dwm from suckless.org
- Color scheme: Solarized Dark
- Font: JetBrainsMono Nerd Font (size 13)
- Tags: 8 workspaces
- Default layout: Tiling with 62% master area

## Requirements

- Xlib header files
- JetBrainsMono Nerd Font
- Applications integrated via keybindings:
  - alacritty (terminal)
  - pulsemixer (audio control)
  - galculator
  - gnome-screenshot
  - slock (screen locker)
  - pcmanfm (file manager)
  - geany (text editor)
  - chromium (web browser)
  - feh (image viewer/wallpaper setter)
  - mpv (media player)

## Installation

1. Verify dependencies are installed
2. Execute:
   ```
   make clean install
   ```

## Execution

Add to .xinitrc:
```bash
exec dwm
```

For status information, add before the exec command:
```bash
while xsetroot -name "$(date +"%Y-%m-%d %H:%M") $(uptime | sed 's/.*,//')"
do
    sleep 60
done &
```

## Key Bindings

### Core Functions

| Key Combination | Function |
|-----------------|----------|
| Alt+p | Application launcher (dmenu) |
| Alt+Shift+Return | Launch terminal (alacritty) |
| Alt+b | Toggle status bar |
| Alt+j/k | Navigate windows |
| Alt+h/l | Resize master area |
| Alt+i/d | Increase/decrease number of windows in master area |
| Alt+Shift+c | Close window |
| Alt+t/f/m | Set layout (tiling/floating/monocle) |
| Alt+0-9 | Switch to tag |
| Alt+Shift+q | Quit dwm |

### Custom Functions

| Key Combination | Function |
|-----------------|----------|
| Alt+Shift+v | Audio control (pulsemixer) |
| Alt+= | Calculator (galculator) |
| Alt+F9 | Screenshot (gnome-screenshot) |
| Alt+F10 | Lock screen (slock) |
| Alt+Home | File manager (pcmanfm) |
| Alt+Menu | Edit tasks file (~/d/etc/t.txt) |
| Alt+/ | Web browser (chromium) |
| Alt+Page_Down | Random wallpaper from ~/i/wp/ |
| Alt+Super_L | Play music from ~/m directory |

## Configuration

All configuration is done by editing config.h and recompiling the source code:

```bash
# After editing config.h
make clean install
```

## Color Scheme

This build uses the Solarized Dark color scheme with blue accent for selected items. The colors are defined in config.h and can be modified by editing the respective color values.

## Layout Settings

- Default master area ratio: 62% of screen width
- Available layouts: Tiling []=, Floating ><>, Monocle [M]
- Default number of clients in master area: 1

## Mouse Controls

- Alt+Left click: Move window
- Alt+Right click: Resize window
- Alt+Middle click: Toggle floating state

---

## License

This project is released under the MIT/X Consortium License - see the original dwm repository for details.

---

*This is a fork of [dwm](https://dwm.suckless.org/) by suckless.org*
