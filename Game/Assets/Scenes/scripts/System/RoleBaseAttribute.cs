using System.Collections;
using System.Collections.Generic;
using UnityEditorInternal.VR;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;
using UnityEngine.SocialPlatforms;

public class RoleBaseAttribute : MonoBehaviour
{
    /// <summary>
    /// 等级
    /// </summary>
    public int level;
    /// <summary>
    /// 攻击间隔
    /// </summary>
    public float AttackInterval;
    /// <summary>
    /// 攻击速度
    /// </summary>
    public float AttackSpeed;
    /// <summary>
    /// 最大生命值 
    /// </summary>
    public float MaxHp;
    /// <summary>
    /// 现在生命值
    /// </summary>
    public float NowHp;
    /// <summary>
    /// 最大技力
    /// </summary>
    public float MaxMp;
    /// <summary>
    /// 现在技力
    /// </summary>
    public float NowMp;
    /// <summary>
    /// 物理防御力
    /// </summary>
    public float PhyDef;
    /// <summary>
    /// 魔法防御力
    /// </summary>
    public float MagDef;
    /// <summary>
    /// 面板攻击力
    /// </summary>
    public float Attack;
    /// <summary>
    /// 攻击范围s
    /// </summary>
    public int[] AttackRange = new int[10];
    public bool IsEnemy;

    /// <summary>
    /// 一技能是否使用
    /// </summary>
    public bool WantToUseSkill1;
    /// <summary>
    /// 二技能是否使用
    /// </summary>
    public bool WantToUseSkill2;
    /// <summary>
    /// 三技能是否使用
    /// </summary>
    public bool WantToUseSkill3;
    /// <summary>
    /// 拥有的技能数量
    /// </summary>
    public int SkillNum;
    /// <summary>
    /// 攻击类型 LongRange,ShortRange,Heal
    /// </summary>
    public string AttackType;

    /// <summary>
    /// 投掷物
    /// </summary>
    public GameObject Missile;

    /// <summary>
    /// 所在X轴
    /// </summary>
    public int x;
    /// <summary>
    /// 所在Y轴
    /// </summary>
    public int y;

    /// <summary>
    /// 攻击后触发持续一帧
    /// </summary>
    public bool AfterAttack;
    /// <summary>
    /// 被攻击后 持续一帧
    /// </summary>
    public bool AfterUnderattack;






    /// <summary>
    /// 时间计算(不可修改)
    /// </summary>
    private float time;
    /// <summary>
    /// 获取动画组件（不可修改）
    /// </summary>
    private Animator anim;
    /// <summary>
    /// 获取Vars组件
    /// </summary>
    private ManagerVars vars;






    void Start()
    {
        vars = ManagerVars.GetManager();
        time = AttackInterval;
        anim = GetComponent<Animator>();
        if (x != 0 && y != 0)
        {
            transform.position = GetPlace();
        }
    }
    public Vector2 GetPlace()
    {
        Vector2 vt2;
        vt2.x = x * 1.93f -9.72f;
        vt2.y = y * 2.15f -3.36f;
        return vt2;
    }

    public Vector2 GetBlockPlace(int x,int y)
    {
        Vector2 vt2;
        vt2.x = -8.88f + (x - 1) * 1.92f;
        vt2.y = -2.67f + (y - 1) * 2.17f;
        return vt2;
    }
    public void UnderAttack(float damage,string type)
    {
        if (type == "Phy")
        {
            float f = damage - PhyDef;
            float g = damage * 0.05f;
            damage = ((f) > (g) ? (f) : (g));
        }
        if (type == "Mag")
        {
            damage *= (1.0f - 0.01f * MagDef);
        }


        NowHp -= damage;
    }
    public Collider2D FindEnemy(string type,int[] Range)
    {
        Collider2D[] AllCollider = new Collider2D[20];
        int head = 0;
        for (int i = 0; i < Range.Length; i ++)
        {
            int _x, _y;
            Vector2 vtl, vtr;
            _x = x + (Range[i] / 100 % 10) * ((Range[i] / 1000 == 1) ? -1 : 1);
            _y = y + (Range[i] % 10) * ((Range[i] % 100 / 10 == 1) ? -1 : 1);
            Vector2 kk = GetBlockPlace(_x, _y);
            vtl.x = kk.x;
            vtl.y = kk.y;
            vtr.x = kk.x + 1.92f;
            vtr.y = kk.y + 2.17f;
            Collider2D[] a = Physics2D.OverlapAreaAll(vtr, vtl);
            for (int j = 0; j < a.Length; j ++)
            {
                AllCollider[head] = a[j];
                head++;
            }
        }

        if (type == "AttackFar")
        {
            for (int i = 0; i < AllCollider.Length; i ++)
            {
                RoleBaseAttribute n = AllCollider[i].GetComponent<RoleBaseAttribute>();
                if (n.IsEnemy == true)
                {
                   // Debug.Log(AllCollider[i]);
                    return AllCollider[i];
                }
            }
        }


        //       Physics2D.OverlapAreaAll();
        return null;
    }
    public void ThroBullet(GameObject Bullet,Collider2D Enemy,float Damage,float Wait)
    {
        RoleBaseAttribute EnemyNumerical = Enemy.GetComponent<RoleBaseAttribute>();
        var ed2 = Enemy.transform.position;
        Vector2 vt2 = GetPlace();
        GameObject go = Instantiate(Bullet);

        var pos = go.transform.position;
        pos.x = vt2.x + 0.5f;
        pos.y = vt2.y;
        go.transform.position = pos;

        //go.transform.rotation = angle; 

        ButtenMoveSystem goMove = go.GetComponent<ButtenMoveSystem>();
        goMove.tim = 1.0f;
        goMove.speed = 6;
        goMove.enemy = Enemy;
        goMove.damage = Damage;
        goMove.count = -1 * Wait;


        var k = goMove.transform.localScale;
        goMove.transform.localScale = k;

    }
    private void Update()
    {
        anim.SetInteger("Attack", 0);
        AfterAttack = false;

        time += Time.deltaTime * 100;

        
        Collider2D kil  = FindEnemy(AttackType,AttackRange);

        //Debug.Log(kil);
        
        if (time > (AttackInterval)*(1-(AttackSpeed * 0.02)/(1+ AttackSpeed * 0.02)) && kil != null)
        {
            ThroBullet(Missile,kil,Attack,0.15f);
            NowMp++;
            anim.SetInteger("Attack", 1);
            time = 0;
            AfterAttack = true;
        }
        
    }
}
