// vote jail
// bbb 99.1.25
#include <vote.h> 
#include <ansi.h>
#define V_JAIL 9

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  string *juror, my_id;

  if (me == victim)
  {
	if (random(2)) me->add("vote/abuse", 10);
  	return notify_fail("你不是开玩笑吧？当心被剥夺表决权！\n");
  }

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_JAIL))
  {
  	return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");
  }

  if( victim->query("jail_on") ) 
  {
  	return notify_fail(victim->name()+"已经被送到监狱坐牢去了。\n");
  }

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_JAIL); 
  }
  
  my_id = me->query("id");

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 ) 
  {
 	victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
	me->add("vote/abuse", 10);
  	return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");
  }

  vv = (int) ("/cmds/std/vote")->valid_voters(me)/6;  
  vc = victim->add("vote/count", 1);

  df = vv - vc;
  if (vv < 4) df = 4 - vc;

  if (df>0)
  { 
        shout( HIG "【表决】"+me->name(1)+"投票将"+victim->name(1)+"("+capitalize(victim->query("id"))+")"
			+"投入监狱，还差"+chinese_number(df)+"票。\n" NOR);
	write( HIG "【表决】"+me->name(1)+"投票将" +victim->name(1)
			+"投入监狱，还差"+chinese_number(df)+"票。\n" NOR);
	victim->apply_condition("vote_clear", 10);
  } else 
  {
        shout( HIG "【表决】"+me->name(1)+"投票将" +victim->name(1)+"("+capitalize(victim->query("id"))+")"
			+"投入监狱。"+victim->name(1)+"被送到监狱坐牢去了！\n" NOR);
	write( HIG "【表决】"+me->name()+"投票将" +victim->name()
			+"投入监狱。"+victim->name(1)+"被送到监狱坐牢去了！\n" NOR);
			
	victim->apply_condition("vote_clear", -10);
	victim->set("jail_on", 1);
	victim->move("/u/wyz/jianyu.c");
  } 
  
  return 1;
}