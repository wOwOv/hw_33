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
ReqProcCreateMe(player,buf);
break;
}
case DEFPROCCREATEOTHER:
{
ReqProcCreateOther(player,buf);
break;
}
case DEFPROCCREATEOTHER:
{
ReqProcCreateOther(player,buf);
break;
}
case DEFPROCDELETE:
{
ReqProcDelete(player,buf);
break;
}
case DEFPROCMOVESTART:
{
ReqProcMoveStart(player,buf);
break;
}
case DEFPROCMOVESTART:
{
ReqProcMoveStart(player,buf);
break;
}
case DEFPROCMOVESTOP:
{
ReqProcMoveStop(player,buf);
break;
}
case DEFPROCATTACK1:
{
ReqProcAttack1(player,buf);
break;
}
case DEFPROCATTACK2:
{
ReqProcAttack2(player,buf);
break;
}
case DEFPROCATTACK3:
{
ReqProcAttack3(player,buf);
break;
}
case DEFPROCDAMAGE:
{
ReqProcDamage(player,buf);
break;
}
default:
{
break;
}
}

