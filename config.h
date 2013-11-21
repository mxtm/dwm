/*
dwm config.h
by Max Tamer-Mahoney <max@mxtm.me>
*/

/* See LICENSE file for copyright and license details (from suckless). */

/* includes (would go below if we needed them) */

/* appearance */
static const char font[]            = "monospace 8";
static const char normbordercolor[] = "#5e7175";
static const char normbgcolor[]     = "#262729";
static const char normfgcolor[]     = "#a3babf";
static const char selbordercolor[]  = "#1692d0";
static const char selbgcolor[]      = "#262729";
static const char selfgcolor[]      = "#ffffff";
static const char fnrmbordercolor[] = "#9e6ffe";
static const char fselbordercolor[] = "#f92671";
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 9;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* path to dwm binary (for restarting) */
static char dwmpath[] = "/home/mxtm/.bin/dwm";

/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "Wine",     NULL,       NULL,       0,            True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	/* these layout symbols only appear properly in my patched Tewi */
	{ "",        tile },
	{ "",        bstack },
	{ "⠶",        gaplessgrid },
	{ "",        spiral },
	{ "",        monocle },
	{ "",        NULL }, /* floating */
};

/* key definitions */
#define MODKEY Mod4Mask /* super key */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */

/* essential */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "termite", NULL };

/* screenlock */
static const char *lockcmd[]  = { "slock", NULL };

/* volume */
static const char *volmutecmd[] = { "pulseaudio-ctl", "mute", NULL };
static const char *volupcmd[] = { "pulseaudio-ctl", "up", NULL };
static const char *voldowncmd[] = { "pulseaudio-ctl", "down", NULL };

/* media */
static const char *playpausekeycmd[] = { "mpc", "toggle", NULL };
static const char *backkeycmd[] = { "mpc", "prev", NULL };
static const char *forwardkeycmd[] = { "mpc", "next", NULL };

/* keyboard layout switching */
static const char *englishkbcmd[] = { "setxkbmap", "-layout", "us", "-variant", "altgr-intl", NULL };
static const char *arabickbcmd[] = { "setxkbmap", "-layout", "ara", "-variant", "basic", NULL };

/* key bindings */

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_q,      spawn,          {.v = lockcmd } },
	{ 0,                XF86XK_AudioMute,      spawn,          {.v = volmutecmd } },
	{ 0,         XF86XK_AudioRaiseVolume,      spawn,          {.v = volupcmd } },
	{ 0,         XF86XK_AudioLowerVolume,      spawn,          {.v = voldowncmd } },
	{ 0,                XF86XK_AudioPlay,      spawn,          {.v = playpausekeycmd } },
	{ 0,                XF86XK_AudioPrev,      spawn,          {.v = backkeycmd } },
	{ 0,                XF86XK_AudioNext,      spawn,          {.v = forwardkeycmd } },
	{ 0,        XF86XK_MonBrightnessDown,      spawn,          {.v = englishkbcmd } },
	{ 0,          XF86XK_MonBrightnessUp,      spawn,          {.v = arabickbcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ MODKEY|ShiftMask,             XK_r,      restart,        {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[1]} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
