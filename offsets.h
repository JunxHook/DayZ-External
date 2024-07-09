#pragma once
#include <Windows.h>

#define OFF_TEXT				0x10
#define OFF_LENGTH				0x8
#define OFF_WORLD				0x414CF70  // 0x413B418 //0x413EE78
#define OFF_NEAR_ENTITY_TABLE	0x0F48
#define OFF_FAR_ENTITY_TABLE	0x1090
#define OFF_SLOW_ENTITY_TABLE	0x2010
#define OFF_skeletonPlayer	0x820
#define OFF_skeletonZombie	0x698
 #define OFF_BULLET	0xD70
#define OFF_BULLETSIZE	OFF_BULLET + 8
#define OFF_NETWORK				0x634
#define off_world_itemtable	 0x2060 
 #define off_world_itemtableSize	 off_world_itemtable +8
#define OFF_NETWORK_MANAGER          0xEE7A88 //22+   21: 0xEE7A80   VEREMOS AGORA
#define OFF_NETWROK_CLIENT           0x48     //22+   21: same
#define OFF_NETWORK_SCOREBOARD       0x10     //22+   21: 0x10 
#define OFF_NETWORK_SCOREBOARD_SIZE  0x1c     //22+   21: same
#define OFF_NETWORK_SCOREBOARD_ID    0x30     //22+   21: same
#define OFF_NETWORK_SCOREBOARD_NAME  0xF0     //22+   21: same
#define OFF_NETWORK_ID               0x6DC    //22+   21: 0x6DC  
 