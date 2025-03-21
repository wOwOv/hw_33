#ifndef __MessageSTUB__
#define __MessageSTUB__

struct Player;
struct SBuffer;

#define DEFPROCCREATEME 0
#define DEFPROCCREATEOTHER 1
#define DEFPROCDELETE 2
#define DEFPROCMOVESTART 11
#define DEFPROCMOVESTOP 13
#define DEFPROCATTACK1 21
#define DEFPROCATTACK2 23
#define DEFPROCATTACK3 25
#define DEFPROCDAMAGE 30


void ReqProcCreateMe(Player* player,SBuffer* buf);
void ReqProcCreateOther(Player* player,SBuffer* buf);
void ReqProcDelete(Player* player,SBuffer* buf);
void ReqProcMoveStart(Player* player,SBuffer* buf);
void ReqProcMoveStop(Player* player,SBuffer* buf);
void ReqProcAttack1(Player* player,SBuffer* buf);
void ReqProcAttack2(Player* player,SBuffer* buf);
void ReqProcAttack3(Player* player,SBuffer* buf);
void ReqProcDamage(Player* player,SBuffer* buf);
void MessageProc(Player* player,SBuffer* buf);


#endif