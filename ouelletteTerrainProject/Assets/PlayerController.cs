using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : Movement {

	void FixedUpdate () {
        Move(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));
	}
}
