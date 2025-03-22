# TechEliteAutomation Builds

This repository contains my custom builds of 'suckless' software tools optimized for Arch Linux.

## Overview

The `bld` repository houses minimal, performance-focused builds of 'suckless' software that I've customized for my personal workflow on Arch Linux with a focus on efficiency and minimalism.

## Included Builds

### dwm (Dynamic Window Manager)

A highly customized build of the 'suckless' dynamic window manager with:

- Optimized for keyboard-driven workflow
- Custom keybindings for efficient window management
- Minimalist aesthetic with a clean status bar
- Performance tweaks for Arch Linux

→ [View dwm configuration](./dwm/)

### slstatus ('suckless' Status Monitor)

A lightweight status monitor displaying essential system information:

- Battery percentage (BAT0)
- CPU usage percentage
- RAM usage percentage
- WiFi signal strength and ESSID (wlan0)
- Date and time with 1-second refresh rate

→ [View slstatus configuration](./slstatus/)

## Screenshots

![slstatus in action](/slstatus/screenshot.png)
![dwm in action](/dwm/screenshot.png)

## Requirements

- Arch Linux
- Xorg
- Basic build tools (`base-devel` package group)
- Xlib headers

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/TechEliteAutomation/bld.git
   cd bld
   ```

2. Build and install dwm:
   ```bash
   cd dwm
   sudo make clean install
   cd ..
   ```

3. Build and install slstatus:
   ```bash
   cd slstatus
   sudo make clean install
   ```

4. Add to your `.xinitrc`:
   ```bash
   # Start status bar
   slstatus &
   
   # Start dwm
   exec dwm
   ```

## Customization

Each directory contains its own configuration files:

- `dwm/config.h` - DWM configuration
- `slstatus/config.h` - Status bar configuration

After making changes, rebuild the respective tool with `sudo make clean install` from its directory.

## Performance

These builds are designed for minimal resource usage while providing all essential functionality. They work exceptionally well on older hardware and are thoroughly optimized for the DWM/Arch workflow.
