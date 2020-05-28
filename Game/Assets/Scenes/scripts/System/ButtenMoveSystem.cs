using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtenMoveSystem : MonoBehaviour
{
    public float move_x;
    public float move_y;
    /// <summary>
    /// 投掷持续时间
    /// </summary>
    public float tim;
    public float count;
    public Collider2D enemy;
    public float damage ;
    private void Start()
    {
        var k = transform.position;
        k.z = -999;
        transform.position = k;
    }
    void Update()
    {
        count += Time.deltaTime;
        if (count > 0)
        {
            var k = transform.position;
            k.x += move_x * Time.deltaTime;
            k.y += move_y * Time.deltaTime;

            

            k.z = 0;
            transform.position = k;
            if (tim < count)
            {
                NormalAttackMissile en = enemy.GetComponent<NormalAttackMissile>();
                en.UnderAttack(damage,"Mag");
                Object.Destroy(gameObject);
            }
        }
    }
}
