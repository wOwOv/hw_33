#ifndef __MessageSTUB__
#define __MessageSTUB__

struct Player;
struct SBuffer;

#define DEFPROCCREATEME -1
#define DEFPROCCREATEOTHER 0
#define DEFPROCDELETE 1
#define DEFPROCMOVESTART 10
#define DEFPROCMOVESTOP 12
#define DEFPROCATTACK1 20
#define DEFPROCATTACK2 22
#define DEFPROCATTACK3 24
#define DEFPROCDAMAGE 29


void ReqProcCreateMe(Player* player,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp);
void ReqProcCreateOther(Player* player, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp);
void ReqProcDelete(Player* player);
void ReqProcMoveStart(Player* player, unsigned char dir, unsigned short x, unsigned short y);
void ReqProcMoveStop(Player* player, unsigned char dir, unsigned short x, unsigned short y);
void ReqProcAttack1(Player* player, unsigned char dir, unsigned short x, unsigned short y);
void ReqProcAttack2(Player* player, unsigned char dir, unsigned short x, unsigned short y);
void ReqProcAttack3(Player* player, unsigned char dir, unsigned short x, unsigned short y);
void ReqProcDamage(Player* player,unsigned int tgt,unsigned char hp);
void MessageProc(Player* player,SBuffer* buf);


#endif