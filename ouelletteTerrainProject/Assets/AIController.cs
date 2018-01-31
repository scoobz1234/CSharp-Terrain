using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

[RequireComponent(typeof(Rigidbody))]

public class AIController : Movement {

    public Vector3 otherPosition;
    public Transform Player, Target;
    public float threshold = -1.5f;
    public GameObject spotted, heard;
    public bool isSpotted = false, isHeard = false;

    void FixedUpdate()
    {
        if (Player)
        {
            Vector3 forward = transform.forward;
            otherPosition = transform.position - Player.position;
            Vector3 targetDir = Player.position - transform.position;

            float angle = Vector3.Angle(targetDir, forward);
            var dist = Vector3.Distance(Player.position, transform.position);

            Vector3 angleCheck = transform.InverseTransformPoint(Player.position);

            if (angleCheck.x < 0){
                angle = -angle;
            }

            if (angle < 45.0f && dist < 20.0f){
                spotted.SetActive(true);
                isSpotted = true;
                Move(angle, 80f);
            }
            else{
                spotted.SetActive(false);
                isSpotted = false;
            }
            if (!isSpotted && angle < 360 && dist < 50.0f){
                heard.SetActive(true);
                isHeard = true;
                Move(angle, 0);
            }
            else{
                heard.SetActive(false);
                isHeard = false;
            }
            if (isSpotted) {
                
            }
        }
    }
}