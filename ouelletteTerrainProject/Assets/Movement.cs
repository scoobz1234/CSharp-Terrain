using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))] 
public class Movement : MonoBehaviour {
    public float Speed = 100.0f;
    public float angularSpeed = 50f;
    public Rigidbody rb;

    void Start(){
        rb = GetComponent<Rigidbody>();
    }

    protected void Move(float rotAngle, float moveSpeed) {

        Vector3 forward = transform.forward;

        rb.AddForce(forward * Speed * moveSpeed);
        rb.AddTorque(Vector3.up * angularSpeed * rotAngle);

    }
}
