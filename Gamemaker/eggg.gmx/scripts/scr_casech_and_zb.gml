if (main_id.name == "raceter")
{
    main_id.brain += bag_wq_brain[place];
    main_id.potence += bag_wq_potence[place];
    main_id.brain -= r_wq_brain[argument0];
    main_id.potence -= r_wq_potence[argument0];
       


    r_mag_attack += bag_wq_attack_mag[place];
    r_phy_attack += bag_wq_attack_phy[place];
    r_defense += bag_wq_defense[place];
    r_element += bag_wq_element[place];
    r_hit_rate += bag_wq_hit_rate[place];
    r_evade += bag_wq_evade[place];
    r_brain += bag_wq_brain[place];
    r_potence += bag_wq_potence[place];
    r_lesscd += bag_wq_lesscd[place];
    r_skillpower *= 1+bag_wq_skillpower[place]/100;
    r_spellspeed += bag_wq_spellspeed[place];
    r_movespeed += bag_wq_movespeed[place];
    r_critical += bag_wq_critical[place];
    r_criti += bag_wq_criti[place];
    
    r_mag_attack -= r_wq_attack_mag[argument0];
    r_phy_attack -= r_wq_attack_phy[argument0];
    r_defense -= r_wq_defense[argument0];
    r_element -= r_wq_element[argument0];
    r_hit_rate -= r_wq_hit_rate[argument0];
    r_evade -= r_wq_evade[argument0];
    r_brain -= r_wq_brain[argument0];
    r_potence -= r_wq_potence[argument0];
    r_lesscd -= r_wq_lesscd[argument0];
    r_skillpower /= 1+r_wq_skillpower[argument0]/100;
    r_spellspeed -= r_wq_spellspeed[argument0];
    r_movespeed -= r_wq_movespeed[argument0];
    r_critical -= r_wq_critical[argument0];
    r_criti -= r_wq_criti[argument0];
    
    r_wq_pz[argument0] =  bag_wq_pz[place];
    r_wq_name[argument0] = bag_wq_name[place];
    r_wq_spr[argument0] =  bag_wq_spr[place]; 
    r_wq_place[argument0] =  bag_wq_place[place];
    r_wq_attack_mag[argument0] = bag_wq_attack_mag[place];
    r_wq_attack_phy[argument0] = bag_wq_attack_phy[place];
    r_wq_defense[argument0] = bag_wq_defense[place];
    r_wq_element[argument0] = bag_wq_element[place];
    r_wq_hit_rate[argument0] = bag_wq_hit_rate[place];
    r_wq_evade[argument0] = bag_wq_evade[place];
    r_wq_brain[argument0] = bag_wq_brain[place];
    r_wq_potence[argument0] = bag_wq_potence[place];
    r_wq_lesscd[argument0] = bag_wq_lesscd[place];
    r_wq_skillpower[argument0] = bag_wq_skillpower[place];
    r_wq_spellspeed[argument0] = bag_wq_spellspeed[place];
    r_wq_movespeed[argument0] = bag_wq_movespeed[place];
    r_wq_critical[argument0] = bag_wq_critical[place];
    r_wq_criti[argument0] = bag_wq_criti[place];   
    scr_equip_have(1,r_wq_name[argument0]);
}
    