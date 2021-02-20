using UnityEngine;

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
    private RoleBaseAttribute main;

    
    void Start()
    {
        main = GetComponent<RoleBaseAttribute>();
    }

    void Update()
    {
        if (main.WantToUseSkill1)
        {
            main.WantToUseSkill1 = false;
            main.ThroBullet(Misslie, main.FindEnemy(main.AttackType,main.AttackRange),main.Attack*2.1f,0.6f);
        }
    }
}
