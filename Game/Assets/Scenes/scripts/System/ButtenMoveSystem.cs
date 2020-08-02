using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtenMoveSystem : MonoBehaviour
{
    public float move_x;
    public float move_y;
    public float speed;
    /// <summary>
    /// 投掷持续时间
    /// </summary>
    public float tim;
    public float count;
    public Collider2D enemy;
    public float damage;
    public string type;
    private void Start()
    {
        var k = transform.position;
        k.z = -999;
        transform.position = k;
    }
    void Update()
    {
        //transform.Translate(new Vector3(move_x * Time.deltaTime, move_y * Time.deltaTime,0));
        transform.rotation = ManagerVars.GetAngle(transform.position, enemy.transform.position);
        //Debug.Log(r);
        Vector2 vt = enemy.transform.position - transform.position;

        //float r = transform.eulerAngles.z;
        //move_x = speed * Mathf.Cos(r);
        //move_y = speed * Mathf.Sin(r);

        float q = Mathf.Sqrt((vt.x * vt.x) + (vt.y * vt.y));
        move_x = speed * vt.x / q;
        move_y = speed * vt.y / q;

        count += Time.deltaTime;
        if (count > 0)
        {
            var k = transform.position;
            k.x += move_x * Time.deltaTime;
            k.y += move_y * Time.deltaTime;

            Vector2 vtr, vtl;
            var self = transform.position;
            vtr.x = self.x - 0.5f;
            vtr.y = self.y - 0.5f;
            vtl.x = self.x + 0.5f;
            vtl.y = self.y + 0.5f;


            Collider2D[] a = Physics2D.OverlapAreaAll(vtr, vtl);

            k.z = 0;
            transform.position = k;
            if (a[0] == enemy)
            {
                RoleBaseAttribute en = enemy.GetComponent<RoleBaseAttribute>();
                en.UnderAttack(damage,"Mag");
                Object.Destroy(gameObject);
            }
            if (tim > 1000)
            {
                Object.Destroy(gameObject);
            }
        }
    }
}
