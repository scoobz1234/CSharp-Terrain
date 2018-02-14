using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : Actor, IAttack<GameObject, int>, IDestructable<int>
{
    public GameObject[] Enemies;
    bool isHitting = false;

    void Start(){
        health = 100;
        maxHealth = 100;
        strength = 25;
        Enemies = GameObject.FindGameObjectsWithTag("Enemy");
    }
   
    public void ApplyDamage(GameObject t, int d) {
        t.GetComponent<NPC>().health -= d;
    }

    public void TakeDamage(int d) {
        health -= d;
    }

    void OnCollisionEnter(Collision other) {
        if (other.gameObject.tag == "Enemy" && isHitting) {
            ApplyDamage(other.gameObject, strength);
        }
    }

}
