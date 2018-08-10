/***************************************************************************
 * rcpmsg.h
 *
 *
 *
 *
 * Functional level: 1
 *
 * Prepared: Dirk Handzic
 *
 *
 * Rev   Date       Author   Ext int. (Y/N)   Reason/description
 * 0.2   130314     DH       Y                rcpmsg_GetRecipes added
 * 0.1   130301     DH       Y                Initial version
 *
 *
 * User interface function
 ***************************************************************************/

#ifndef rcpmsg_def
#define rcpmsg_def




typedef unsigned char  UCHAR;
typedef unsigned short UINT;
typedef unsigned long  ULONG;
typedef signed short INT;
typedef signed char CHAR;
typedef signed long LONG;
typedef float FLOAT;

enum BOOL_TYPE {DFALSE,DTRUE};
enum STRENGTH {DEFAULT_STRENGTH, MILD_MIX, NORMAL_MIX, STRONG_MIX};
enum CUPSIZE {DEFAULT_SIZE, SMALL_CUP, MEDIUM_CUP, LARGE_CUP};
enum CON_TYPE {NO_CON, LIQ_COFFEE, LIQ_DECAF, LIQ_MILK, LIQ_TEA, LIQ_CHOCO, INS_MILK, INS_TEA, INS_CHOCO, INS_SUGAR};
enum PROD_TYPE {LEFT_BIB, RIGHT_BIB, CANISTER};
enum RCPMSG_STATE {RCP_PARSE, RCP_SEND_I, RCP_SEND_E, RCP_DONE, RCP_REQ_E, RCP_REQ_SEND_I, RCP_REQ_NO, RCP_WAIT_NO, RCP_REQ_WAIT_REPLY, RCP_REQ_DONE};

#define BOOL enum BOOL_TYPE






#endif

