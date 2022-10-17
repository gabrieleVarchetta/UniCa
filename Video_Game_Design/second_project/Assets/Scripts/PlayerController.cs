using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private Rigidbody sphereRB;

    [SerializeField]
    float speed = 5f;
    float jump_speed = 10f;
    bool can_jump = true;
    float fixed_jump;

    // Start is called before the first frame update
    void Start()
    {
        sphereRB = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        //you can jump as long as you press space
        //float jump = Input.GetAxis("Jump");

        Vector3 force = new(horizontalInput * speed, 0f, verticalInput * speed);

        sphereRB.AddForce(force, ForceMode.Acceleration);
        Jump();
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space) && can_jump)
        {
            can_jump = false;
            fixed_jump = jump_speed;
        }

    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.CompareTag("Collectable"))
        {
            //Destroy(other.gameObject);
            other.gameObject.SetActive(false);
        }
    }

    private void OnCollisionStay(Collision collision)
    {
        if(collision.gameObject.CompareTag("Terrain"))
            can_jump = true;
    }

    private void OnCollisionExit(Collision collision)
    {
        if(collision.gameObject.CompareTag("Terrain"))
            can_jump = false;
    }

    private void Jump()
    {
        //you can jump only when you press space one time
        if(fixed_jump != 0)
        {
            sphereRB.AddForce(new Vector3(0f, fixed_jump, 0f), ForceMode.Impulse);
            fixed_jump = 0;
        }
    }
}
