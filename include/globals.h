// globals.h
// this file will be automatically included by the driver
// for XKX mudlib, by Xiang
#ifndef __GLOBALS_H__
#define __GLOBALS_H__
#include "ansi.h"

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected static
#endif


// Important directories
#define INC_DIR     "/include/"
#define COMMAND_DIR "/cmds/"
#define CONFIG_DIR  "/adm/etc/"
#define DATA_DIR    "/data/"
#define HELP_DIR    "/doc/"
#define LOG_DIR     "/log/"
// Daemons
#define ALIAS_D     "/adm/daemons/aliasd"
#define BAN_D       "/adm/daemons/band"
#define CHANNEL_D   "/adm/daemons/channeld"
#define CHAR_D      "/adm/daemons/chard"
#define CHINESE_D   "/adm/daemons/chinesed"
#define COMBAT_D    "/adm/daemons/combatd"
#define COMMAND_D   "/adm/daemons/commandd"
#define EMOTE_D     "/adm/daemons/emoted"
#define FINGER_D    "/adm/daemons/fingerd"
#define FTP_D       "/adm/daemons/ftpd"
#define INQUIRY_D   "/adm/daemons/inquiryd"
#define LOGIN_D     "/adm/daemons/logind"
#define MONEY_D     "/adm/daemons/moneyd"
#define NATURE_D    "/adm/daemons/natured"
#define PIG_D       "/adm/daemons/pigd"
#define PROFILE_D   "/adm/daemons/profiled"
#define RANK_D      "/adm/daemons/rankd"
#define SECURITY_D  "/adm/daemons/securityd"
// #define SECURITY_D  "/adm/daemons/securd"
#define UPDATE_D    "/adm/daemons/updated"
#define VIRTUAL_D   "/adm/daemons/virtuald"
#define MONITOR_D   "/adm/daemons/monitord"
#define WEAPON_D    "/adm/daemons/weapond"
#define LANGUAGE_D    "/adm/daemons/languaged"
#define STATUS_D    "/adm/daemons/statud"
#define TASK_D        "/adm/daemons/questd"
#define CRON_D            "/adm/daemons/cron"
// Added for questing
// by Hop, 1997.05.16
#define QUEST_D(x)  ("/quest/qlist" + x)
// End of appendence
#define CLASS_D(x)  ("/kungfu/class/" + x)
#define SKILL_D(x)  ("/kungfu/skill/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
// Clonable/Non-inheritable Standard Objects
#define CORPSE_OB   "/clone/misc/corpse"
#define LOGIN_OB    "/clone/user/login"
#define MASTER_OB   "/adm/obj/master"
#define MAILBOX_OB  "/clone/misc/mailbox"
#define THGOLD_OB   "/clone/money/thousand-gold" 
#define THCASH_OB   "/clone/money/thousand-cash"
#define GOLD_OB     "/clone/money/gold"
#define SILVER_OB   "/clone/money/silver"
#define COIN_OB     "/clone/money/coin"
#define SIMUL_EFUN_OB   "/adm/obj/simul_efun"
#define USER_OB     "/clone/user/user"
#define VOID_OB     "/clone/misc/void"
// Inheritable Standard Objects
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define BULLETIN_JBOARD "/inherit/misc/jboard"
#define CHARACTER   "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP       "/inherit/misc/equip"
#define FORCE       "/inherit/skill/force"
#define HOCKSHOP    "/inherit/room/hockshop"
#define ITEM        "/inherit/item/item"
#define LIQUID      "/inherit/food/liquid"
#define MONEY       "/inherit/item/money"
#define NPC     "/inherit/char/npc"
#define PILL        "/inherit/medicine/pill"
#define POWDER      "/inherit/medicine/powder"
#define ROOM        "/inherit/room/room"
#define SKILL       "/inherit/skill/skill"
#define SELL_SALT   "/inherit/char/sell_salt"
#define NPC_SAVE	"/inherit/char/npcsave"
#define QUEST            "/inherit/quest"

// #define USER-ROOM   "/inherit/room/user_room"
// User IDs
#define ROOT_UID    "Root"
#define BACKBONE_UID    "Backbone"
// Features
#define F_ACTION        "/feature/action.c"
#define F_ALIAS         "/feature/alias.c"
#define F_APPRENTICE        "/feature/apprentice.c"
#define F_ATTACK        "/feature/attack.c"
#define F_ATTRIBUTE     "/feature/attribute.c"
#define F_AUTOLOAD      "/feature/autoload.c"
#define F_CLEAN_UP      "/feature/clean_up.c"
#define F_COMMAND       "/feature/command.c"
#define F_CONDITION     "/feature/condition.c"
#define F_DAMAGE        "/feature/damage.c"
#define F_DBASE         "/feature/dbase.c"
#define F_DEALER        "/feature/dealer.c"
#define F_EDIT          "/feature/edit.c"
#define F_EQUIP         "/feature/equip.c"
#define F_FINANCE       "/feature/finance.c"
#define F_FOOD          "/feature/food.c"
#define F_LIQUID        "/feature/liquid.c"
#define F_MASTER        "/inherit/char/master.c"
#define F_MESSAGE       "/feature/message.c"
#define F_MORE          "/feature/more.c"
#define F_MOVE          "/feature/move.c"
#define F_NAME          "/feature/name.c"
#define F_SAVE          "/feature/save.c"
#define F_BACKUP     "/feature/backup.c"
#define F_SKILL         "/feature/skill.c"
#define F_TEAM          "/feature/team.c"
#define F_TREEMAP       "/feature/treemap.c"
#define F_VENDOR        "/feature/dealer.c"
#define F_SSERVER       "/feature/sserver.c"
#define F_UNIQUE        "/feature/unique.c"
#define F_BANKER        "/feature/banker.c"

#define SKILL_MODEL_UNARMED    "/meskill/skill_model_unarmed.c"

#define SKILL_MODEL_WEAPON     "/meskill/skill_model_weapon.c"
#define SKILL_MODEL_DEFAULT    "/meskill/skill_model_default.c"
#define F_VENDOR_SALE		"/feature/vendor_sale.c"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.
#undef PROFILE_COMMANDS

#include "tomud.h"

#define F_GEMS			"/feature/gems.c"
#define S_WEAPON		"/inherit/gems/weapon.c"
#define S_ROBE			"/inherit/gems/robe.c"
#define S_RING			"/inherit/gems/ring.c"

#define STORY_DIR       "/clone/gift/"
#define STORY_D	        "/adm/daemons/storyd"
#endif
