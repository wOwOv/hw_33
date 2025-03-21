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