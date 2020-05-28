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
    public int k;
}
