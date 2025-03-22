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
ReqProcCreateMe(player,dir,x,y,hp);
break;
}
case DEFPROCCREATEOTHER:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
 unsigned char hp;
*buf>>dir>>x>>y>>hp;
ReqProcCreateOther(player,dir,x,y,hp);
break;
}
case DEFPROCDELETE:
{
*buf;
ReqProcDelete(player);
break;
}
case DEFPROCMOVESTART:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcMoveStart(player,dir,x,y);
break;
}
case DEFPROCMOVESTOP:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcMoveStop(player,dir,x,y);
break;
}
case DEFPROCATTACK1:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcAttack1(player,dir,x,y);
break;
}
case DEFPROCATTACK2:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcAttack2(player,dir,x,y);
break;
}
case DEFPROCATTACK3:
{
 unsigned char dir;
 unsigned short x;
 unsigned short y;
*buf>>dir>>x>>y;
ReqProcAttack3(player,dir,x,y);
break;
}
case DEFPROCDAMAGE:
{
unsigned int tgt;
unsigned char hp;
*buf>>tgt>>hp;
ReqProcDamage(player,tgt,hp);
break;
}
default:
{
break;
}
}
}

