#include "Messageproxy.h"
#include "SerialBuffer.h"
#include "SendCast.h"


void UProcCreateMe(Player* player,unsigned int id,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=10;
unsigned char type=0;
buf<<code<<size<<type;
buf<<id<<dir<<x<<y<<hp;

SendUnicast(player,&buf);
}

void RBProcCreateMe(unsigned int id,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=10;
unsigned char type=0;
buf<<code<<size<<type;
buf<<<<<<<<<<;

SendBroadcast(nullptr,&buf);
}

void BProcCreateMe(Player* player,unsigned int id,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=10;
unsigned char type=0;
buf<<code<<size<<type;
buf<<<<<<<<<<;

SendBroadcast(player,&buf);
}

void UProcCreateOther(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=10;
unsigned char type=1;
buf<<code<<size<<type;
buf<<id<<dir<<x<<y<<hp;

SendUnicast(player,&buf);
}

void RBProcCreateOther(unsigned int id, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=10;
unsigned char type=1;
buf<<code<<size<<type;
buf<<<<<<<<<<;

SendBroadcast(nullptr,&buf);
}

void BProcCreateOther(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=10;
unsigned char type=1;
buf<<code<<size<<type;
buf<<<<<<<<<<;

SendBroadcast(player,&buf);
}

void UProcDelete(Player* player,unsigned int id)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=4;
unsigned char type=2;
buf<<code<<size<<type;
buf<<id;

SendUnicast(player,&buf);
}

void RBProcDelete(unsigned int id)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=4;
unsigned char type=2;
buf<<code<<size<<type;
buf<<;

SendBroadcast(nullptr,&buf);
}

void BProcDelete(Player* player,unsigned int id)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=4;
unsigned char type=2;
buf<<code<<size<<type;
buf<<;

SendBroadcast(player,&buf);
}

void UProcMoveStart(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=11;
buf<<code<<size<<type;
buf<<id<<dir<<x<<y;

SendUnicast(player,&buf);
}

void RBProcMoveStart(unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=11;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(nullptr,&buf);
}

void BProcMoveStart(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=11;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(player,&buf);
}

void UProcMoveStop(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=13;
buf<<code<<size<<type;
buf<<id<<dir<<x<<y;

SendUnicast(player,&buf);
}

void RBProcMoveStop(unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=13;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(nullptr,&buf);
}

void BProcMoveStop(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=13;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(player,&buf);
}

void UProcAttack1(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=21;
buf<<code<<size<<type;
buf<<id<<dir<<x<<y;

SendUnicast(player,&buf);
}

void RBProcAttack1(unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=21;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(nullptr,&buf);
}

void BProcAttack1(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=21;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(player,&buf);
}

void UProcAttack2(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=23;
buf<<code<<size<<type;
buf<<id<<dir<<x<<y;

SendUnicast(player,&buf);
}

void RBProcAttack2(unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=23;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(nullptr,&buf);
}

void BProcAttack2(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=23;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(player,&buf);
}

void UProcAttack3(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=25;
buf<<code<<size<<type;
buf<<id<<dir<<x<<y;

SendUnicast(player,&buf);
}

void RBProcAttack3(unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=25;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(nullptr,&buf);
}

void BProcAttack3(Player* player,unsigned int id, unsigned char dir, unsigned short x, unsigned short y)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=25;
buf<<code<<size<<type;
buf<<<<<<<<;

SendBroadcast(player,&buf);
}

void UProcDamage(Player* player,unsigned int atk,unsigned int tgt,unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=30;
buf<<code<<size<<type;
buf<<atk<<tgt<<hp;

SendUnicast(player,&buf);
}

void RBProcDamage(unsigned int atk,unsigned int tgt,unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=30;
buf<<code<<size<<type;
buf<<<<<<;

SendBroadcast(nullptr,&buf);
}

void BProcDamage(Player* player,unsigned int atk,unsigned int tgt,unsigned char hp)
{
SBuffer buf;
unsigned char code=0x89;
unsigned char size=9;
unsigned char type=30;
buf<<code<<size<<type;
buf<<<<<<;

SendBroadcast(player,&buf);
}

