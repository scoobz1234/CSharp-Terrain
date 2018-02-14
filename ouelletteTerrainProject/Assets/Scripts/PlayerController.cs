using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class PlayerController : Movement {

public bool isGrounded = false;

    void FixedUpdate () {
        Move(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));

        if (isGrounded){
            if (Input.GetKeyUp(KeyCode.Space)){
                rb.AddForce(0, 50, 0, ForceMode.Impulse);
            }
        }
    }

    void OnCollisionStay(Collision collision){
        isGrounded = true;
    }
    void OnCollisionExit(Collision collision){
        isGrounded = false;
    }
}
