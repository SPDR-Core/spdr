
Debian
====================
This directory contains files used to package spdrd/spdr-qt
for Debian-based Linux systems. If you compile spdrd/spdr-qt yourself, there are some useful files here.

## spdr: URI support ##


spdr-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install spdr-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your spdrqt binary to `/usr/bin`
and the `../../share/pixmaps/spdr128.png` to `/usr/share/pixmaps`

spdr-qt.protocol (KDE)

