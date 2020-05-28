using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.UIElements;

public class VeryCoolAxe : MonoBehaviour
{
    /// <summary>
    /// 投掷物
    /// </summary>
    public GameObject Misslie;
    
    //private 


    /// <summary>
    /// 获取主角的属性值
    /// </summary>
    private NormalAttackMissile main;

    
    void Start()
    {
        main = GetComponent<NormalAttackMissile>();
    }

    void Update()
    {
        if (main.WantToUseSkill1)
        {
            main.WantToUseSkill1 = false;
            main.ThroBullet(Misslie, main.FindEnemy(main.AttackType),main.Attack*2.1f,0.6f);
        }
    }
}
