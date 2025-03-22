#include "Messagestub.h"
#include "Struct.h"
#include "SerialBuffer.h"

void MessageProc(Player* player,SBuffer* buf)
{
unsigned char code;
unsigned char size;
unsigned char type;
*buf>>code>>size>>type;
switch(type)
{
case DEFPROCCREATEME:
{
unsigned char dir;
unsigned short x;
unsigned short y;
unsigned char hp;
*buf>>dir>>x>>y>>hp;
ReqProcCreateMe(Player* player,unsigned char dir,unsigned short x,unsigned short y,unsigned char hp);
break;
}
case DEFPROCCREATEOTHER:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
 unsigned char hp;
*buf>>dir>>x>>y>>hp;
ReqProcCreateOther(Player* player, unsigned char dir, unsigned short x, unsigned short y, unsigned char hp);
break;
}
case DEFPROCDELETE:
{
*buf;
ReqProcDelete(Player* player);
break;
}
case DEFPROCMOVESTART:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcMoveStart(Player* player, unsigned char dir, unsigned short x, unsigned short y);
break;
}
case DEFPROCMOVESTOP:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcMoveStop(Player* player, unsigned char dir, unsigned short x, unsigned short y);
break;
}
case DEFPROCATTACK1:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcAttack1(Player* player, unsigned char dir, unsigned short x, unsigned short y);
break;
}
case DEFPROCATTACK2:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcAttack2(Player* player, unsigned char dir, unsigned short x, unsigned short y);
break;
}
case DEFPROCATTACK3:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcAttack3(Player* player, unsigned char dir, unsigned short x, unsigned short y);
break;
}
case DEFPROCDAMAGE:
{
unsigned int tgt;
unsigned char hp;
*buf>>tgt>>hp;
ReqProcDamage(Player* player,unsigned int tgt,unsigned char hp);
break;
}
default:
{
break;
}
}
}

