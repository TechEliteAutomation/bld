static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=13" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=13";
static const char col_base03[]      = "#002b36"; /* Background */
static const char col_base02[]      = "#073642"; /* Lighter Background */
static const char col_base01[]      = "#586e75"; /* Comments, Secondary Content */
static const char col_base00[]      = "#657b83"; /* Default Foreground */
static const char col_base0[]       = "#839496"; /* Lighter Foreground */
static const char col_base1[]       = "#93a1a1"; /* Lighter Content */
static const char col_base2[]       = "#eee8d5"; /* Light Background */
static const char col_base3[]       = "#fdf6e3"; /* Very Light Background */
static const char col_yellow[]      = "#b58900";
static const char col_orange[]      = "#cb4b16";
static const char col_red[]         = "#dc322f";
static const char col_magenta[]     = "#d33682";
static const char col_violet[]      = "#6c71c4";
static const char col_blue[]        = "#268bd2";
static const char col_cyan[]        = "#2aa198";
static const char col_green[]       = "#859900";
static const char *colors[][3]      = {
	/*               fg          bg          border   */
	[SchemeNorm] = { col_base0,  col_base03, col_base01 }, /* Unfocused */
	[SchemeSel]  = { col_base3,  col_blue,   col_blue  }, /* Focused */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.62; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_base03, "-nf", col_base0, "-sb", col_blue, "-sf", col_base3, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static const Key keys[] = {
	/* modifier			key        	function        argument */
	{ MODKEY,           XK_p,      	spawn,    		{.v = dmenucmd } },
	{ MODKEY|ShiftMask,	XK_Return, 	spawn,          {.v = termcmd } },
	{ MODKEY,           XK_b,      	togglebar,      {0} },
	{ MODKEY,           XK_j,      	focusstack,     {.i = +1 } },
	{ MODKEY,           XK_k,      	focusstack,     {.i = -1 } },
	{ MODKEY,           XK_i,      	incnmaster,     {.i = +1 } },
	{ MODKEY,           XK_d,      	incnmaster,     {.i = -1 } },
	{ MODKEY,           XK_h,      	setmfact,       {.f = -0.05} },
	{ MODKEY,           XK_l,      	setmfact,       {.f = +0.05} },
	{ MODKEY,           XK_Return, 	zoom,           {0} },
	{ MODKEY,           XK_Tab,    	view,           {0} },
	{ MODKEY|ShiftMask, XK_c,      	killclient,     {0} },
	{ MODKEY,           XK_t,      	setlayout,      {.v = &layouts[0]} },
	{ MODKEY,           XK_f,      	setlayout,      {.v = &layouts[1]} },
	{ MODKEY,           XK_m,      	setlayout,      {.v = &layouts[2]} },
	{ MODKEY,           XK_space,  	setlayout,      {0} },
	{ MODKEY|ShiftMask, XK_space,  	togglefloating,	{0} },
	{ MODKEY,           XK_0,      	view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_0,      	tag,            {.ui = ~0 } },
	{ MODKEY,           XK_comma,  	focusmon,       {.i = -1 } },
	{ MODKEY,           XK_period, 	focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask, XK_comma,  	tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask, XK_period, 	tagmon,         {.i = +1 } },
	TAGKEYS(            XK_1,                      	0)
	TAGKEYS(            XK_2,                      	1)
	TAGKEYS(            XK_3,                      	2)
	TAGKEYS(            XK_4,                      	3)
	TAGKEYS(            XK_5,                      	4)
	TAGKEYS(            XK_6,                      	5)
	TAGKEYS(            XK_7,                      	6)
	TAGKEYS(            XK_8,                      	7)
	TAGKEYS(            XK_9,                      	8)
	{ MODKEY|ShiftMask, XK_q,      		quit,       {0} },
	{ MODKEY|ShiftMask, XK_v,           spawn,  	SHCMD("alacritty -e pulsemixer") },
	{ MODKEY, 			XK_equal, 		spawn, 		SHCMD("galculator") },
	{ MODKEY,           XK_F9,         	spawn,  	SHCMD("gnome-screenshot") },
	{ MODKEY,			XK_F10,         spawn,  	SHCMD("slock") },
	{ MODKEY,      		XK_Home, 		spawn,  	SHCMD("pcmanfm") },
	{ MODKEY, 			XK_Menu, 		spawn, 		SHCMD("geany /home/u/d/main/t.txt") },
	{ MODKEY, 			XK_slash, 		spawn, 		SHCMD("chromium --new-window") },
	{ MODKEY, 			XK_Page_Down, 	spawn, 		SHCMD("feh --bg-fill --randomize ~/i/wp/*") },
	{ MODKEY,    		XK_Super_L, 	spawn,  	SHCMD("alacritty -e mpv --no-audio-display --shuffle --loop-playlist=inf /home/u/m") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
