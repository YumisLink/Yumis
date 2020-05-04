using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NormalAttackMissile : MonoBehaviour
{
    /// <summary>
    /// 攻击间隔
    /// </summary>
    public float AttackInterval;

    /// <summary>
    /// 时间计算(不可修改)
    /// </summary>
    private float time;

    void Start()
    {
        time = AttackInterval;
    }

    void Update()
    {
        time++;
        if (time >= AttackInterval)
        {
            GameObject go = Instantiate(S)
        }
    }
}
