//�������в���Ԥ������globals.h��ʵ�֣���TMI�Ķ������£�
//#define TMI(x) (""+x+"")   //(char[25]+x+char[26])

string welmsg = TMI("alert ��ã���ӭ����TOMUD����MUD��չЭ����ʾվ��\n���潫��ʾ��������MUD֧��TOMUD����MUD�ͻ��˵����ֹ���"
		"\n�밴��ָʾ����������Ҫ�˳���������quit���\n"
		"����ʾֻ�Ǽ���ʾ��������κ����ʺͽ��飬�����http://bbs.tomud.com/\nѯ��TOMUDС���Ա��\n"
		"                                                      TOMUD С�� 2002\n");	
string byemsg = TMI("alert �ټ�����ӭ����http://www.tomud.com����л��TOMUD����MUDͨ�ÿͻ��˵Ĺ��ĺ�֧�֣�");
/*
��ʾ���ݣ�
1��ALERT����
2����ʾ�����б����
3��Я����Ʒ�б����
��Ȼ���������б��ɾ����
//4����ʾ�Ҽ��˵�
5����ʾQQ��Ϣ
6����ʾ״̬����Ϣ
*/
mapping sw=([
	"0":
	([
		"info":"��ε���һ��������ʾһЩ��Ϣ",
		"code":"write(TMI(\"alert ��ã�����alert���������Ϣ����ʾ\"))",
		"out" :TMI("alert ��ã�����alert������ʾ"),
		"desc":"Ҫ��TOMUDʵ�ָ��ֹ��ܣ���ؼ�����Ҫ��ָ���ĸ�ʽ��TOMUD�ͻ�����������ַ�����",
	]),
	"1":           
	([
		"info":"�����ӷ����б���Ϣ",
		"code":"write(TMI(\"lbadd0 ���A(playera)01173;\")+TMI(\"lbadd0 ���B(playerb)�ǳ�01174;\")+TMI(\"lbadd0 ��ƷA(objectA)00961;\"))",
		"out" :TMI("lbadd0 ���A(playera)01173;")+TMI("lbadd0 ���B(playerb)�ǳ�01174;")+TMI("lbadd0 ��ƷA(objectA)00961;"),
		"desc":"��������Ŀ�����ڷ����б�������ָ����һ���б����ʹ���б��δ��ʾ��\nҲӦ����������ά���б�����ͬ����",
	]),             
	"2":           
	([
		"info":"��������Ʒ�б���Ϣ",
		"code":"write(TMI(\"lbadd1 ��ƷA(objecta)00961;\")+TMI(\"lbadd1 ��ƷB(objectb)�ǳ�00961;\")+TMI(\"lbadd1 ��ƷC(objectC)00961;\"))",
		"out" :TMI("lbadd1 ��ƷA(objecta)00961;")+TMI("lbadd1 ��ƷB(objectb)�ǳ�00961;")+TMI("lbadd1 ��ƷC(objectC)00961;"),
		"desc":"��������Ŀ�����������Ʒ�б�������һ���б����ʹ���б��δ��ʾ��\nҲӦ����������ά���б�����ͬ����",
	]),  
	"3":           
	([
		"info":"������WHO�б���Ϣ������ͨ����������������ϵ�WHO��ť������",
		"code":"write(TMI(\"lbadd2 ���A(playera)01173;\")+TMI(\"lbadd2 ���B(playerb)�ǳ�01174;\")+TMI(\"lbadd2 ���C(playerC)00961;\"))",
		"out" :TMI("lbadd2 ���A(playera)01173;")+TMI("lbadd2 ���B(playerb)�ǳ�01174;")+TMI("lbadd2 ���C(playerC)00961;"),
		"desc":"��Who��ť�󣬻���������˷���([who �Ұ�Ц������])ȡȫ���б�֮���ٰ�Ҳ���ᷢ��������\n"
			"����lbadd2����Ӧ����ÿ���û�����ʱ�㲥��ͬʱ������ʱ�㲥���б�ɾ����������Ϣ��\n����who�б�Ϳ��Լ�ʱ��ȡ���������",
	]),
	"4":           
	([
		"info":"��δ��б���ɾ���б�����",
		"code":"write(TMI(\"lbrem0 ���A(playera)01173;\")+TMI(\"lbrem1 ��ƷB(objectb)�ǳ�00901;\")+TMI(\"lbrem2 ���C(playerC)00961;\"))",
		"out" :TMI("lbrem0 ���A(playera)01173;")+TMI("lbrem1 ��ƷB(objectb)�ǳ�00901;")+TMI("lbrem2 ���C(playerC)00961;"),
		"desc":"ɾ������Ӻ����ƣ�ֻ��Ҫ���������add����Ϊrem�Ϳ�����",
	]),
	"5":           
	([
		"info":"�����QQ���ڷ�ʽ����˽�Ĵ���",
		"code":"write(TMI(\"ctell name=���;ID=myid;icon=01173;;talk=������Ҫ����˽�ĵĻ�\"))",
		"out" :TMI("ctell name=���;ID=myid;icon=01173;;talk=������Ҫ����˽�ĵĻ�"),
		"desc":"��ʾQQ�Ի����Ǻ����׵ģ�����TOMUD��δ�����滻����ǰϵͳ���tell���������ctell���滻\n"
			"TOMUD��ʾ���������ctell�����TOMUD�ڽ��û�����ظ���ʱ��Ҳ�Ƿ���ctell���������Ҫ\n"
			"��ķ�������Ӹ�������Խ�tell����ƹ���Ȼ���޸�һ��������ּ��ɣ�",
	]),
	"6":           
	([
		"info":"�����״̬������ʾ״̬����",
		"code":"write(TMI(\"statu ��11��22����33����44ʳ55ˮ66Ǳ��77����88\"))",
		"out" :TMI("statu ��11��22����33����44ʳ55ˮ66Ǳ��77����88"),
		"desc":"��ֻ��Ҫ�޸�/feature/message.c�����Ӷ�Ӧ��prompt����Ϳ���ʵ��״̬����ʱ������",
	]),
]);

int swtotal=0;  

void logon(object ob)
{
	write(welmsg);
	swtotal=sizeof(sw);
	write(ALERT("������go���������ʾ��������ʾ"+swtotal+"�"));
	input_to("start_show",ob,0);
	return ;
}

void start_show(string arg,object ob,int step)
{
	mapping m;
	string tmp;
	arg=lower_case(arg);
	if(arg=="who �Ұ�Ц������")
	{
		write(sw["3"]["out"]);
		input_to("start_show",ob,step);
		return ;
	}
	if(arg=="quit" ||arg=="exit" || step==swtotal)
	{
		write(byemsg);
		destruct(ob);
		return ;
	}
	if(sscanf(arg,"actionavailable%*s"))
	{
		string win;
		if( sscanf(arg, "%s,%s", arg, win)!=2)
		{
			write("����");
		}
		if(win=="0")
			write(TMI("mbegin ѡ���������;id")+TMI("mitem �۲�$U;")+TMI("mitem ������ʾ;go")+TMI("mendd"));
		else
			write(TMI("mbegin ѡ��Я������;id")+TMI("mitem �۲�$U;")+TMI("mitem ������ʾ;go")+TMI("mendd"));
		input_to("start_show",ob,step);
		return ;
	}
	if(arg!="go")
	{
		write(ALERT("������go���������ʾ��"));
		input_to("start_show",ob,step);
		return;
	}
	m=sw[""+step];
	if(step<swtotal-1 && step > -1)
	{
		tmp="��һ��go�����ʾ��"+sw[""+(step+1)]["info"];
		write(m["info"]+"\nĿ�ģ�"+m["desc"]+"\nʾ�����룺\n"+m["code"]+"\n\nЧ���Ѿ������\n\n"+tmp+"\n"+m["out"]);
		input_to("start_show",ob,step+1);
	}
	else 
	{
		tmp="�����������������ʾ��";
		write(m["info"]+"\nĿ�ģ�"+m["desc"]+"\nʾ�����룺\n"+m["code"]+"\n\nЧ���Ѿ������\n\n"+tmp+"\n"+m["out"]);
		write(byemsg);
		destruct(ob);
		return;
	}
}
