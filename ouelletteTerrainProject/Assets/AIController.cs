using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

[RequireComponent(typeof(Rigidbody))]

public class AIController : Movement {

    public Transform Player, Target;
    public GameObject spotted, heard, talk;

    enum State {PASSIVE,AGRESSIVE}
    [SerializeField]
    State m_State = State.PASSIVE;

    enum PassiveState {LOOK,WANDER,INTERACT }
    [SerializeField]
    PassiveState m_PassiveState = PassiveState.WANDER;

    enum AgressiveState {IDLE,LOOK,ATTACK}
    [SerializeField]
    AgressiveState m_AgressiveState = AgressiveState.IDLE;

    void Start(){
        spotted.SetActive(false);
        heard.SetActive(false);
        talk.SetActive(false);
    }

    void FixedUpdate(){
        CheckState();
        CheckDistance();
    }

    void CheckState() {
        switch (m_State) {
            case State.PASSIVE:
                CheckPassiveState();
                break;
            case State.AGRESSIVE:
                CheckAgressiveState();
                break;
        }
    }

    void OnDrawGizmos(){
        Gizmos.color = Color.red;
        // Gizmos.DrawWireSphere(transform.position, 20);
        Vector3 direction = transform.TransformDirection(Vector3.forward) * 30;
        Gizmos.DrawRay(transform.position, direction);
    }

    void CheckDistance() {
        RaycastHit hit;
        var dist = Vector3.Distance(Player.position, transform.position);

        if (dist > 30.0f && dist <= 50.0f) {
            m_AgressiveState = AgressiveState.LOOK;
            m_PassiveState = PassiveState.LOOK;
        }

        if (Physics.Raycast(transform.position, Vector3.forward, out hit)) {
            if (hit.transform.GetComponentInParent<PlayerController>())
            {
                m_AgressiveState = AgressiveState.ATTACK;
                m_PassiveState = PassiveState.INTERACT;
            }
        }
        else {
            m_AgressiveState = AgressiveState.IDLE;
            m_PassiveState = PassiveState.WANDER;
        }
    }

    void CheckPassiveState(){
        switch (m_PassiveState) {
            case PassiveState.INTERACT:
                PassiveInteract();
                break;
            case PassiveState.LOOK:
                Look();
                break;
            case PassiveState.WANDER:
                PassiveWander();
                break;
        }
    }
    void CheckAgressiveState() {
        switch (m_AgressiveState) {
            case AgressiveState.IDLE:
                Idle();
                break;
            case AgressiveState.LOOK:
                Look();
                break;
            case AgressiveState.ATTACK:
                AgressiveAttack();
                break;
        }
    }

    void PassiveInteract() {
        heard.SetActive(false);
        talk.SetActive(true);
    }

    void PassiveWander() {
        heard.SetActive(false);
        spotted.SetActive(false);
        talk.SetActive(false);
    }

    void Idle() {
        heard.SetActive(false);
        spotted.SetActive(false);
        talk.SetActive(false);
    }

    void Look() {
        Vector3 targetDir = Player.position - transform.position;
        float angle = Vector3.Angle(targetDir, transform.forward);
        Vector3 angleCheck = transform.InverseTransformPoint(Player.position);

        if (angleCheck.x < 0){
            angle = -angle;
        }

        heard.SetActive(true);
        spotted.SetActive(false);
        talk.SetActive(false);
        Move(angle, 0);
    }

    void AgressiveAttack() {
        Vector3 targetDir = Player.position - transform.position;
        float angle = Vector3.Angle(targetDir, transform.forward);
        Vector3 angleCheck = transform.InverseTransformPoint(Player.position);

        if (angleCheck.x < 0) {
            angle = -angle;
        }

        if (angle < 45.0f){
            float forwardSpeed = 1.0f;
            spotted.SetActive(true);
            heard.SetActive(false);
            talk.SetActive(false);
            Move(angle, forwardSpeed);
        }
    }

}