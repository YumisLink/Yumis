using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "CreateManagerVarsContainer")]
public class ManagerVars : ScriptableObject
{
    public GameObject[] AllPreform = new GameObject[100];
    public GameObject[] AllBullet = new GameObject[100];
    public GameObject[,] PlaceRole = new GameObject[11, 11];
    public int[,] PlaceId = new int[11, 11];
    public static ManagerVars GetManager()
    {
        Debug.Log("?");
        return Resources.Load<ManagerVars>("ManagerContainer");
    }
    /*
    public float GetAngle(Vector2 vt1, Vector2 vt2)
    {
        Vector2 ed;

        ed.x = vt2.x - vt1.x;
        ed.y = vt2.y - vt1.y;
        Debug.Log(ed);

        float angle = Mathf.Atan(1);
        if (ed.y < 0) angle *= -1;
        return angle;

    }
    */
    public static Quaternion GetAngle(Vector2 vt1, Vector2 vt2)
    {
        Vector3 from;
        from.x = 1; 
        from.y = 0;
        from.z = 0;

        Vector3 to = vt2 - vt1;
        to.z = 0;

        var axis = Vector3.Cross(from, to);
        var angle = Vector3.Angle(from, to);
        return Quaternion.AngleAxis(angle, axis.normalized);
    }
    public int k;
}
