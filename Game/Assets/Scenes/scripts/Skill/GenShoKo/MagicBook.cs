using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class MagicBook : MonoBehaviour
{
    RoleBaseAttribute Main;
    float AttackUp;
    int AttackSpeedUp;
    void Start()
    {
        Main = GetComponent<RoleBaseAttribute>();
        int b = 2;
        if (Main.level <= 50)
        {
            b = 1;
        }
        if (Main.level > 130)
        {
            b = 4;
        }
        AttackUp = b * 0.2f * Main.Attack;
        AttackSpeedUp = b * 3;
        Main.Attack += AttackUp;
        Main.AttackSpeed += AttackSpeedUp;
    }

    void Update()
    {
        
    }
}
