#ifndef __Message.h__
#define __Message.h__

struct Player;

void UProcCreateMe(Player* player,unsigned int id,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp);
void UProcCreateOther(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp);
void UProcCreateOther(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp);
void ProcDelete(Player* player,unsigned int id);
void ProcMoveStart(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void ProcMoveStop(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void ProcAttack1(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void ProcAttack2(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void ProcAttack3(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void ProcDamage(Player* player,unsigned int atk,unsigned int tgt,unsigned char hp);


#endif