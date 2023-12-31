#ifndef WORDLIST
#define WORDLIST
#include <vector>
#include <string>
#include <chrono>

int getTheDay()
{
    return (static_cast<int>(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())) - 18000)/86400;
}

std::string getTodaysWord()
{
    static std::vector<std::string> words{
        "SHIRT",
        "LYING",
        "READY",
        "NEVER",
        "CHART",
        "STOOD",
        "STICK",
        "PHONE",
        "MONEY",
        "SHELL",
        "JIMMY",
        "CRAFT",
        "FORTY",
        "CLOSE",
        "ROBIN",
        "SUGAR",
        "AUDIO",
        "AFTER",
        "RATIO",
        "BELOW",
        "ABOUT",
        "AUDIT",
        "MEANT",
        "DYING",
        "SIXTH",
        "HUMAN",
        "GUEST",
        "CIVIL",
        "USAGE",
        "WHOLE",
        "EXIST",
        "PRIDE",
        "VITAL",
        "FOCUS",
        "PHASE",
        "FIELD",
        "LAUGH",
        "ACTOR",
        "WRONG",
        "LEGAL",
        "INNER",
        "LIMIT",
        "IDEAL",
        "TRIED",
        "JONES",
        "DELAY",
        "ANGLE",
        "UPSET",
        "ORDER",
        "DRIVE",
        "BLIND",
        "CROWN",
        "OFTEN",
        "COAST",
        "TAXES",
        "DRESS",
        "CRIME",
        "PRICE",
        "THEIR",
        "TRUST",
        "TRIAL",
        "ARRAY",
        "FLEET",
        "TEACH",
        "DEATH",
        "TOPIC",
        "EXTRA",
        "PRIME",
        "TABLE",
        "BREAD",
        "DRAFT",
        "ASSET",
        "STAGE",
        "GUARD",
        "MIXED",
        "CRASH",
        "THICK",
        "CLAIM",
        "BLOCK",
        "MARIA",
        "QUITE",
        "PLACE",
        "SCOPE",
        "FRANK",
        "ALIKE",
        "SCORE",
        "GOING",
        "NOISE",
        "SPENT",
        "LEARN",
        "QUEEN",
        "SIGHT",
        "EVERY",
        "ADMIT",
        "LINKS",
        "LEVEL",
        "MAJOR",
        "TREND",
        "FRONT",
        "TIRED",
        "SEVEN",
        "UPPER",
        "TEXAS",
        "SKILL",
        "BUYER",
        "NIGHT",
        "SUPER",
        "TRUTH",
        "TRULY",
        "CHECK",
        "FRESH",
        "RIVER",
        "MAGIC",
        "SOLVE",
        "STAND",
        "TOUCH",
        "TAKEN",
        "DEPTH",
        "BRAIN",
        "WORRY",
        "TRUCK",
        "FRAUD",
        "PRIOR",
        "PLAIN",
        "MOUSE",
        "LIGHT",
        "DRILL",
        "PAINT",
        "COUNT",
        "HOTEL",
        "JAPAN",
        "SHAPE",
        "BASIS",
        "NEWLY",
        "WHERE",
        "KNOWN",
        "WORTH",
        "FALSE",
        "DEBUT",
        "JOINT",
        "SLIDE",
        "CYCLE",
        "EQUAL",
        "STILL",
        "FIFTH",
        "ELITE",
        "FULLY",
        "SHALL",
        "WOMEN",
        "RAISE",
        "COULD",
        "SLEEP",
        "SMART",
        "ANGRY",
        "OCCUR",
        "LARGE",
        "BASIC",
        "BLAME",
        "LOCAL",
        "UNTIL",
        "SHARE",
        "WATER",
        "NOTED",
        "POWER",
        "GRANT",
        "PLANT",
        "ERROR",
        "LABEL",
        "SOLID",
        "SUITE",
        "FIRST",
        "THREW",
        "WHILE",
        "ISSUE",
        "BOUND",
        "RANGE",
        "MAYBE",
        "COVER",
        "NORTH",
        "AGAIN",
        "BRING",
        "INPUT",
        "AMONG",
        "SMITH",
        "EARLY",
        "THEME",
        "CHINA",
        "CLEAN",
        "BEING",
        "ALIVE",
        "BREAK",
        "MODEL",
        "PRIZE",
        "ROYAL",
        "QUICK",
        "NOVEL",
        "FIXED",
        "NURSE",
        "THING",
        "MOVIE",
        "TOUGH",
        "SIXTY",
        "VOICE",
        "FLASH",
        "HENCE",
        "SORRY",
        "SIZED",
        "CARRY",
        "PITCH",
        "GROUP",
        "BOOST",
        "LOWER",
        "VALUE",
        "TRAIN",
        "CLOCK",
        "FINAL",
        "STAKE",
        "MARCH",
        "SHOWN",
        "HEART",
        "FORUM",
        "MINOR",
        "MOUNT",
        "WHICH",
        "MATCH",
        "APART",
        "PANEL",
        "BUILT",
        "FIBER",
        "INDEX",
        "THANK",
        "AGREE",
        "BROKE",
        "BEGIN",
        "GROWN",
        "MAYOR",
        "TIMES",
        "GIVEN",
        "STYLE",
        "ARENA",
        "SPEAK",
        "RAPID",
        "FUNNY",
        "ASIDE",
        "OTHER",
        "VALID",
        "AGENT",
        "FLUID",
        "UNION",
        "STAFF",
        "VISIT",
        "DREAM",
        "WORSE",
        "ROUGH",
        "GUESS",
        "SCALE",
        "SMALL",
        "START",
        "ARISE",
        "SHOOT",
        "GUIDE",
        "TERRY",
        "THEFT",
        "CAUSE",
        "CATCH",
        "STOCK",
        "SOUTH",
        "APPLY",
        "SENSE",
        "ROMAN",
        "POUND",
        "JUDGE",
        "HEAVY",
        "TITLE",
        "THROW",
        "LUNCH",
        "MUSIC",
        "RADIO",
        "FRUIT",
        "THIRD",
        "ROGER",
        "HARRY",
        "WHOSE",
        "EAGER",
        "SCENE",
        "SWEET",
        "FIGHT",
        "STORM",
        "PLANE",
        "CLASS",
        "PROVE",
        "BROAD",
        "METAL",
        "SMOKE",
        "TWICE",
        "GLASS",
        "CHIEF",
        "DRAWN",
        "ENTER",
        "GRADE",
        "WASTE",
        "PRESS",
        "LASER",
        "WATCH",
        "ABOVE",
        "PHOTO",
        "GLOBE",
        "GRACE",
        "VIDEO",
        "CHAIR",
        "HAPPY",
        "BEGAN",
        "OFFER",
        "LEASE",
        "ROUTE",
        "LATER",
        "CHIID",
        "BEGUN",
        "ALTER",
        "EAGLE",
        "SARAH",
        "FAITH",
        "SHARP",
        "APPLE",
        "SHELF",
        "FRAME",
        "TRACK",
        "ENTRY",
        "MINUS",
        "TASTE",
        "BOARD",
        "UNDUE",
        "SINCE",
        "URBAN",
        "TRADE",
        "TREAT",
        "TEETH",
        "PAPER",
        "MOTOR",
        "ACUTE",
        "LAYER",
        "DRAMA",
        "MIGHT",
        "POINT",
        "AWARE",
        "TIGHT",
        "EXACT",
        "FORCE",
        "EVENT",
        "DAILY",
        "BAKER",
        "FOUND",
        "USUAL",
        "GRAND",
        "GIANT",
        "CABLE",
        "ALLOW",
        "OUGHT",
        "ALONE",
        "LOGIC",
        "CHASE",
        "BREED",
        "PLATE",
        "WOMAN",
        "CURVE",
        "DANCE",
        "WOULD",
        "FORTH",
        "ROUND",
        "LOOSE",
        "CLICK",
        "SMILE",
        "CREAM",
        "FAULT",
        "UNDER",
        "DOZEN",
        "IMAGE",
        "WORLD",
        "NEEDS",
        "PILOT",
        "TODAY",
        "SHORT",
        "STUCK",
        "BLOOD",
        "SPOKE",
        "SPEED",
        "CLEAR",
        "DROVE",
        "SERVE",
        "UNITY",
        "EMPTY",
        "BRIEF",
        "VIRUS",
        "ANGER",
        "ENJOY",
        "PEACE",
        "THESE",
        "BEACH",
        "PIECE",
        "WORST",
        "PETER",
        "LEAST",
        "SPACE",
        "CROWD",
        "BILLY",
        "QUIET",
        "EARTH",
        "STRIP",
        "FLOOR",
        "DOING",
        "HOUSE",
        "WRITE",
        "BROWN",
        "REACH",
        "MAKER",
        "THINK",
        "CROSS",
        "STONE",
        "THREE",
        "SHEET",
        "SHIFT",
        "CALIF",
        "LEAVE",
        "BRAND",
        "SHOCK",
        "ARGUE",
        "CHAIN",
        "WHITE",
        "WHEEL",
        "BUILD",
        "MEDIA",
        "BADLY",
        "GRASS",
        "STORY",
        "BLACK",
        "LIVES",
        "GREEN",
        "LUCKY",
        "STUFF",
        "STEEL",
        "SPLIT",
        "THOSE",
        "RIVAL",
        "STORE",
        "DOUBT",
        "MOUTH",
        "DRINK",
        "OCEAN",
        "ALERT",
        "ALONG",
        "MONTH",
        "MORAL",
        "REFER",
        "LEWIS",
        "EIGHT",
        "BASES",
        "FIFTY",
        "HORSE",
        "ADULT",
        "CHEAP",
        "COACH",
        "RIGHT",
        "SPARE",
        "SPORT",
        "ALBUM",
        "ADOPT",
        "PARTY",
        "STEAM",
        "STUDY",
        "TOTAL",
        "SPEND",
        "ENEMY",
        "AWARD",
        "WOUND",
        "SOUND",
        "PRINT",
        "DEALT",
        "AVOID",
        "THERE",
        "CHEST",
        "TRIES",
        "ALARM",
        "COURT",
        "BOOTH",
        "STATE",
        "GROSS",
        "BENCH",
        "RURAL",
        "PROOF",
        "ABUSE",
        "HAIRY",
        "GREAT",
        "PROUD",
        "TOWER",
        "CHOSE",
        "BIRTH",
        "AHEAD"
    };
    return words[getTheDay()%words.size()];
}


#endif