#include <X11/XF86keysym.h>

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[] = { "monospace:size=8" };
static const char dmenufont[]       = "monospace:size=8";
static const char normbordercolor[] = "#5e7175";
static const char normbgcolor[]     = "#262729";
static const char normfgcolor[]     = "#a3babf";
static const char selbordercolor[]  = "#1692d0";
static const char selbgcolor[]      = "#262729";
static const char selfgcolor[]      = "#ffffff";
static const char *colors[][3] 		= {
	/*               fg           bg           border           */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { selfgcolor, selbgcolor,   selbordercolor},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance    title       tags mask     isfloating   monitor */
	{ "Gimp",           NULL,       NULL,       0,            True,        -1 },
	{ "Wine",           NULL,       NULL,       0,            True,        -1 },
	{ "mpv",            NULL,       NULL,       0,            True,        -1 },
	{ "Mullvad",        NULL,       NULL,       0,            True,        -1 },
	{ "Spotify",        NULL,       NULL,       0,            True,        -1 },
	{ "Tor Browser",    NULL,       NULL,       0,            True,        -1 },
	{ "DTA",            NULL,       NULL,       0,            True,        -1 },
	{ "Navigator",      NULL,       NULL,       0,            True,        -1 },
	{ "pinentry",       NULL,       NULL,       0,            True,        -1 },
	{ "Yubico Authenticator", NULL,     NULL,       0,            True,        -1 },
	{ "ArmoryQt.py",    NULL,       NULL,       0,            True,        -1 },
	{ "SpeedCrunch",    NULL,       NULL,       0,            True,        -1 },
	{ "zoom",           NULL,       NULL,       0,            True,        -1 },
	{ NULL,             NULL,       "Eddie",    0,            True,        -1 },
	{ "VirtualBox Machine",       NULL,       NULL,       1 << 5,            False,        -1 },
	{ "VirtualBox Manager",       NULL,       NULL,       1 << 4,            False,        -1 }
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	//{ "",        tile },    /* first entry is default */
	//{ "",        htile },
	//{ "",        monocle },
	//{ "",        NULL },    /* no layout function means floating behavior */
	{ "T",        tile },    /* first entry is default */
	//{ "H",        htile },
	{ "<>",        monocle },
	{ "F",        NULL },    /* no layout function means floating behavior */
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
/* essentials */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "termite", NULL };

/* screenlock */
static const char *lockcmd[]  = { "slock", NULL };

/* volume */
static const char *volmutecmd[] = { "amixer", "sset", "Master", "toggle", NULL };
static const char *volupcmd[] = { "amixer", "sset", "Master", "5%+", NULL };
static const char *voldowncmd[] = { "amixer", "sset", "Master", "5%-", NULL };

/* media */
static const char *playpausekeycmd[] = { "mpc", "toggle", NULL };
static const char *backkeycmd[] = { "mpc", "prev", NULL };
static const char *forwardkeycmd[] = { "mpc", "next", NULL };

/* keyboard layout switching */
static const char *engkbcmd[] = { "setxkbmap", "-layout", "us", "-variant", "altgr-intl", NULL };
static const char *arakbcmd[] = { "setxkbmap", "-layout", "ara", "-variant", "buckwalter", NULL };

/* crn typer */
static const char *crncmd[] = { "crn", NULL };

/* quit confirmation dmenu script */
static const char *quitcmd[] = { "power", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_q,      spawn,          {.v = lockcmd } },
	{ 0,                XF86XK_AudioMute,      spawn,          {.v = volmutecmd } },
	{ 0,         XF86XK_AudioRaiseVolume,      spawn,          {.v = volupcmd } },
	{ 0,         XF86XK_AudioLowerVolume,      spawn,          {.v = voldowncmd } },
	{ 0,                  XF86XK_LaunchA,      spawn,          {.v = crncmd } },
	//{ 0,                XF86XK_AudioPlay,      spawn,          {.v = playpausekeycmd } },
	//{ 0,                XF86XK_AudioPrev,      spawn,          {.v = backkeycmd } },
	//{ 0,                XF86XK_AudioNext,      spawn,          {.v = forwardkeycmd } },
	//{ 0,        XF86XK_MonBrightnessDown,      spawn,          {.v = engkbcmd } },
	//{ 0,          XF86XK_MonBrightnessUp,      spawn,          {.v = arakbcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_j,      pushdown,       {0} },
	{ MODKEY|ShiftMask,             XK_k,      pushup,         {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[2]} },
	// { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	// { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
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
	TAGKEYS(                        XK_6,                      5)
	{ MODKEY|ShiftMask,             XK_q,      spawn,          {.v = quitcmd } },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	// { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	// { ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	// { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

