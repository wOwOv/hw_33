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
}
case DEFPROCCREATEOTHER:
{
ReqProcCreateOther(player,buf);
}
case DEFPROCCREATEOTHER:
{
ReqProcCreateOther(player,buf);
}
case DEFPROCDELETE:
{
ReqProcDelete(player,buf);
}
case DEFPROCMOVESTART:
{
ReqProcMoveStart(player,buf);
}
case DEFPROCMOVESTART:
{
ReqProcMoveStart(player,buf);
}
case DEFPROCMOVESTOP:
{
ReqProcMoveStop(player,buf);
}
case DEFPROCATTACK1:
{
ReqProcAttack1(player,buf);
}
case DEFPROCATTACK2:
{
ReqProcAttack2(player,buf);
}
case DEFPROCATTACK3:
{
ReqProcAttack3(player,buf);
}
case DEFPROCDAMAGE:
{
ReqProcDamage(player,buf);
}
}

