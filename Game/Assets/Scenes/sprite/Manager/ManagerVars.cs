using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "CreateManagerVarsContainer")]
public class Manager : ScriptableObject
{
    public GameObject[,] PlaceRole = new GameObject[7, 10];

}
