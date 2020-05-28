using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Animations;

public class BattleControler : MonoBehaviour
{
    /// <summary>
    /// 观测值
    /// </summary>
    public int Look ;
    private ManagerVars vars;
    void Start()
    {
        vars = ManagerVars.GetManager();
        
        vars.PlaceId[1, 1] = 1;
        /*
        vars.PlaceId[2, 2] = 1;
        vars.PlaceId[3, 3] = 1;
        vars.PlaceId[4, 4] = 1;
        vars.PlaceId[5, 3] = 1;
        vars.PlaceId[6, 2] = 1;
        vars.PlaceId[7, 1] = 1;
        vars.PlaceId[8, 2] = 1;
        */
        vars.PlaceId[9, 1] = 2;
        vars.k = 100;







        for (int i = 1; i <= 9; i ++)
        {
            Look = i;
            for (int j = 1; j <= 4; j ++)
                {
                    Look = i;
                    if (vars.PlaceId[i, j] != 0)
                    {
                        vars.PlaceRole[i,j] = Object.Instantiate(vars.AllPreform[vars.PlaceId[i, j]]);
                        NormalAttackMissile a = vars.PlaceRole[i, j].GetComponent<NormalAttackMissile>();
                        var scale = vars.PlaceRole[i, j].transform.localScale;
                            scale.x *= -1;
                        if (i > 4)
                        {
                            vars.PlaceRole[i, j].transform.localScale = scale;
                        }
                        a.x = i;a.y = j;
                    }
                }
            }
    }

    // Update is called once per frame
    void Update()
    { 

    }
}
