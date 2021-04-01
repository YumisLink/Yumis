var a = argument0;
var pz = 1;
var place = "没有";
var attack_phy = 0;
var attack_mag = 0;
var spr = spr_jlzn;
var defense = 0;
var hit_rate = 0;
var evade = 0;
var brain = 0;
var potence = 0;
var lesscd = 0;
var skillpower = 0;
var spellspeed = 0;
var movespeed = 0;
var critical = 0;
var element = 0;
var criti = 0;
if (argument1 == "巨龙之怒-星空的征服者")
{
    pz = 5;
    place = "长刀";
    attack_phy = irandom_range(650,700);
    attack_mag = irandom_range(630,669);
    spr = spr_jlzn;
    brain = irandom_range(60,80);
    potence = irandom_range(60,80);
    skillpower = 30;
    criti = 25;
}
if (argument1 == "屠戮者的镣铐")
{
    pz = 5;
    place = "手镯";
    spr = spr_tlzdlk;
    defense = 2;
    potence = irandom_range(36,43);
}

if (argument1 == "毁灭之眼")
{
    pz = 5;
    place = "项链";
    spr = spr_hmzy;
    defense = 2;
    brain = irandom_range(36,43);
}

if (argument1 == "半巨人之怒")
{
    pz = 5;
    place = "戒指";
    spr = spr_bjrzn;
    defense = 2;
    brain = irandom_range(57,64);
    potence = irandom_range(57,64);
}

if (argument1 == "艾拉斯的轨迹")
{
    pz = 5;
    place = "手镯";
    spr = spr_alsdgj;
    defense = 2;
    potence = irandom_range(36,43);
}
if (argument1 == "维斯特卢")
{
    pz = 5;
    place = "项链";
    spr = spr_wstl;
    defense = 2;
    brain = irandom_range(36,43);
}
if (argument1 == "银河之星")
{
    pz = 5;
    place = "戒指";
    spr = spr_yhzx;
    defense = 2;
    brain = irandom_range(57,64);
    potence = irandom_range(57,64);
    criti = 20;
}
if (argument1 == "永恒战术")
{
    pz = 5;
    place = "头肩";
    spr = spr_yhzs;
    defense = 4;
    brain = irandom_range(144,167);
    potence = irandom_range(144,167);
}
if (argument1 == "倾塌之墙")
{
    pz = 5;
    place = "上衣";
    spr = spr_qtzq;
    defense = -50;
    brain = irandom_range(155,177);
    potence = irandom_range(155,177);
    skillpower = 25;
}

if (argument1 == "斯洛特的原初之力")
{
    pz = 5;
    place = "下装";
    spr = spr_sltdyczl;
    defense = 4;
    brain = irandom_range(166,177);
    potence = irandom_range(166,177);
}
if (argument1 == "诺萨的灵魂挽歌")
{
    pz = 5;
    place = "鞋";
    spr = spr_nsdlhwg;
    defense = 4;
    brain = irandom_range(133,158);
    potence = irandom_range(133,158);
}
if (argument1 == "崇高的幻象")
{
    pz = 5;
    place = "头肩";
    spr = spr_cgdhx;
    defense = 4;
    brain = irandom_range(144,167);
    potence = irandom_range(144,167);
}

if (argument1 == "时轮驾驭者")
{
    pz = 5;
    place = "上衣";
    spr = spr_sljyz;
    defense = 4;
    brain = irandom_range(155,177);
    potence = irandom_range(155,177);
}
if (argument1 == "半巨人的背叛")
{
    pz = 5;
    place = "下装";
    spr = spr_bgrdbp;
    defense = 4;
    brain = irandom_range(166,177);
    potence = irandom_range(166,177);
}
if (argument1 == "维利的预言")
{
    pz = 5;
    place = "鞋";
    spr = spr_wldyy;
    defense = 4;
    brain = irandom_range(133,158);
    potence = irandom_range(133,158);
}


if (argument1 == "浮光花园")
{
    pz = 5;
    place = "头肩";
    spr = spr_fghy;
    defense = 2;
    brain = irandom_range(167,188);
    potence = irandom_range(35,65);
}
if (argument1 == "印记迷园")
{
    pz = 5;
    place = "上衣";
    spr = spr_msdydgs;
    defense = 2;
    brain = irandom_range(198,224);
    potence = irandom_range(35,65);
}
if (argument1 == "伊贝拉的梦境")
{
    pz = 5;
    place = "下装";
    spr = spr_ybldmj;
    defense = 2;
    brain = irandom_range(165,187);
    potence = irandom_range(64,86);
}
if (argument1 == "精灵天舞")
{
    pz = 5;
    place = "鞋";
    spr = spr_jltw;
    defense = 2;
    brain = irandom_range(105,125);
    potence = irandom_range(32,45);
}
if (argument1 == "松之礼赞")
{
    pz = 5;
    place = "头肩";
    spr = spr_szlz;
    defense = 2;
    brain = irandom_range(198,224);
    potence = irandom_range(35,65);
}
if (argument1 == "精灵之翼")
{
    pz = 5;
    place = "上衣";
    spr = spr_jlzy;
    defense = 2;
    movespeed = 50;
    brain = irandom_range(198,224);
    potence = irandom_range(35,65);
}
if (argument1 == "夏夜星象馆")
{
    pz = 5;
    place = "下装";
    spr = spr_xyxxg;
    defense = 2;
    brain = irandom_range(165,187);
    potence = irandom_range(64,86);
}
if (argument1 == "月光漫步")
{
    pz = 5;
    place = "鞋";
    spr = spr_ygmb;
    defense = 2;
    brain = irandom_range(105,125);
    potence = irandom_range(32,45);
}
if (argument1 == "幸运的白兔")
{
    pz = 5;
    place = "项链";
    spr = spr_xydbt;
    defense = 5;
    brain = irandom_range(56,73);
}
if (argument1 == "圣路易斯的轨迹")
{
    pz = 5;
    place = "项链";
    spr = spr_slysdgj;
    defense = 5;
    brain = irandom_range(56,73);
}
if (argument1 == "不动的大图书馆")
{
    pz = 5;
    place = "手镯";
    spr = spr_bdddtsg;
    defense = 5;
    brain = irandom_range(26,33);
}
if (argument1 == "英雄王的象征")
{
    pz = 5;
    place = "手镯";
    spr = spr_yxwdxz;
    defense = 5;
    brain = irandom_range(26,33);
}
if (argument1 == "幻想的狐嫁雨")
{
    pz = 5;
    place = "戒指";
    spr = spr_hxdhjy;
    defense = 5;
    brain = irandom_range(77,84);
    potence = irandom_range(37,44);
}
if (argument1 == "怜月的约定")
{
    pz = 5;
    place = "戒指";
    spr = spr_lydyd;
    defense = 5;
    brain = irandom_range(77,84);
    potence = irandom_range(37,44);
}
if (argument1 == "艾露尼斯")
{
    pz = 5;
    place = "魔杖";
    attack_phy = irandom_range(740,780);
    spr = spr_alns;
    defense = 5;
    brain = irandom_range(233,255);
}
if (argument1 == "杰米尼-冥影之霍德尔")
{
    pz = 5;
    place = "魔杖";
    spr = spr_xydbt;
    attack_phy = irandom_range(740,780);
    element = 60;
    defense = 5;
    brain = irandom_range(233,255);
}





if (argument1 == "雄鹰之心")
{
    pz = 5;
    place = "手镯";
    spr = spr_xyzx;
    defense = 5;
    movespeed = 20;
    potence = irandom_range(36,43);
}
if (argument1 == "希望的回响")
{
    pz = 5;
    place = "戒指";
    spr = spr_xydbt;
    defense = 5;
    brain = irandom_range(57,64);
    potence = irandom_range(57,64);
}
if (argument1 == "萨瓦里克的杰作")
{
    pz = 5;
    place = "项链";
    spr = spr_swdk;
    defense = 5;
    brain = irandom_range(56,73);
}
if (argument1 == "永恒梦境")
{
    pz = 5;
    place = "项链";
    spr = spr_yhmj;
    defense = -25;
    brain = irandom_range(56,73);
}
if (argument1 == "超时空护腕")
{
    pz = 5;
    place = "手镯";
    spr = spr_cskhw;
    defense = 5;
    potence = irandom_range(36,43);
}
if (argument1 == "死亡之拥")
{
    pz = 5;
    place = "戒指";
    spr = spr_swzy;
    defense = 5;
    brain = irandom_range(57,64);
    potence = irandom_range(57,64);
}
if (argument1 == "燃烧的地狱核心")
{
    pz = 5;
    place = "头肩";
    spr = spr_rsddyhx;
    defense = 10;
    brain = irandom_range(133,155);
    potence = irandom_range(133,155);
}
if (argument1 == "法术理论")
{
    pz = 5;
    place = "上衣";
    spr = spr_fsll;
    defense = 10;
    brain = irandom_range(133,155);
    potence = irandom_range(133,155);
}
if (argument1 == "狂风骤雨")
{
    pz = 5;
    place = "下装";
    spr = spr_kfzy;
    defense = 10;
    brain = irandom_range(133,155);
    potence = irandom_range(133,155);
}
if (argument1 == "云中漫步")
{
    pz = 5;
    place = "鞋";
    spr = spr_yzmb;
    defense = 10;
    brain = irandom_range(133,155);
    potence = irandom_range(133,155);
}
if (argument1 == "思维火花")
{
    pz = 5;
    place = "头肩";
    spr = spr_swhh;
    defense = 10;
    criti = 10;
    brain = irandom_range(133,155);
    potence = irandom_range(133,155);
}
if (argument1 == "记忆支配者")
{
    pz = 5;
    place = "上衣";
    spr = spr_jyzpz;
    defense = 10;
    brain = irandom_range(133,155);
    potence = irandom_range(133,155);
}
if (argument1 == "创世者柱石")
{
    pz = 5;
    place = "下装";
    spr = spr_cszzs;
    defense = 10;
    brain = irandom_range(133,155);
    potence = irandom_range(133,155);
}
if (argument1 == "空间加速器")
{
    pz = 5;
    place = "鞋";
    spr = spr_kjjsq;
    defense = 10;
    movespeed = 10;
    brain = irandom_range(133,155);
    potence = irandom_range(133,155);
}












b = bag_wq_stack;
bag_wq_stack ++

bag_wq_element[b] = element
bag_wq_pz[b] = pz
bag_wq_name[b] = argument1
bag_wq_place[b] = place
bag_wq_attack_phy[b] = attack_phy
bag_wq_attack_mag[b] = attack_mag
bag_wq_spr[b] = spr
bag_wq_defense[b] = defense
bag_wq_hit_rate[b] = hit_rate
bag_wq_evade[b] = evade
bag_wq_brain[b] = brain
bag_wq_potence[b] = potence
bag_wq_lesscd[b] = lesscd
bag_wq_skillpower[b] = skillpower
bag_wq_spellspeed[b] = spellspeed
bag_wq_movespeed[b] = movespeed
bag_wq_critical[b] = critical
bag_wq_criti[b] = criti