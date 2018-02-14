using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NPC : Actor, IAttack<GameObject, int>, IDestructable<int>
{

    bool isHitting = false;

    void Start() {
        maxHealth = 100;
        health = 100;
        strength = 10;
    }

    public void ApplyDamage(GameObject t, int d){
        t.GetComponent<Player>().health -= d;
    }

    public void TakeDamage(int d){
        health -= d;
    }

    void OnCollisionEnter(Collision other){
        if (other.gameObject.tag == "Player" && isHitting)
        {
            ApplyDamage(other.gameObject, strength);
        }
    }
}
