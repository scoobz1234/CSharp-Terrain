using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface IAttack<TT,TD>{
    void ApplyDamage(TT Target, TD damageAmmount);
}

public interface IDestructable<TD> {
    void TakeDamage(TD damageAmmount);
}
