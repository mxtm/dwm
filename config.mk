# dwm config.mk
# patched by Max Tamer-Mahoney with Runiq's fixes for building on Arch

# dwm version
VERSION = 6.0

# paths
PREFIX = /usr
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/include/X11
X11LIB = /usr/lib/X11

# Xinerama
XINERAMALIBS = -L${X11LIB} -lXinerama
XINERAMAFLAGS = -DXINERAMA

# includes and libs
INCS = -I. -I/usr/include -I${X11INC} `pkg-config --cflags xft pango pangoxft`
LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS} `pkg-config --libs xft pango pangoxft`

# flags
CPPFLAGS += -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
LDFLAGS = -s ${LIBS}

# compiler and linker
CC = cc
