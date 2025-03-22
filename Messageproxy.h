#ifndef __MessagePROXY__
#define __MessagePROXY__

struct Player;

void UProcCreateMe(Player* player,unsigned int id,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp);
void RBProcCreateMe(unsigned int id,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp);
void BProcCreateMe(Player* player,unsigned int id,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp);
void UProcCreateOther(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp);
void RBProcCreateOther(unsigned int id, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp);
void BProcCreateOther(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp);
void UProcDelete(Player* player,unsigned int id);
void RBProcDelete(unsigned int id);
void BProcDelete(Player* player,unsigned int id);
void UProcMoveStart(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void RBProcMoveStart(unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void BProcMoveStart(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void UProcMoveStop(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void RBProcMoveStop(unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void BProcMoveStop(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void UProcAttack1(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void RBProcAttack1(unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void BProcAttack1(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void UProcAttack2(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void RBProcAttack2(unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void BProcAttack2(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void UProcAttack3(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void RBProcAttack3(unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void BProcAttack3(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y);
void UProcDamage(Player* player,unsigned int atk,unsigned int tgt,unsigned char hp);
void RBProcDamage(unsigned int atk,unsigned int tgt,unsigned char hp);
void BProcDamage(Player* player,unsigned int atk,unsigned int tgt,unsigned char hp);


#endif