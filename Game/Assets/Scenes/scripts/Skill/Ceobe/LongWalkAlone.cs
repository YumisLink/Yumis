using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class LongWalkAlone : MonoBehaviour
{
    public float[] Range = new float[4];
    private bool LongWalkAloneOn;
    RoleBaseAttribute main;
    /// <summary>
    /// 攻击力提升量
    /// </summary>
    private float AddAtt;
    /// <summary>
    /// 攻击速度提升量
    /// </summary>
    private float AddSpeed;
    void Start()
    {
        LongWalkAloneOn = true;
        main = GetComponent<RoleBaseAttribute>();
        AddAtt = main.Attack * 0.08f;
        AddSpeed = 8;
    }

    void Update()
    {
        

    }
}
