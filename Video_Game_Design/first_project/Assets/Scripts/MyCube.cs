using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MyCube : MonoBehaviour
{

    private Vector3 rotation = new Vector3(0f, 1f, 0f);

    [SerializeField]
    private float speed = 5f;

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("Uela");
    }

    private void Update()
    {
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        transform.position += new Vector3(horizontalInput * speed * Time.deltaTime, 0f, verticalInput * speed * Time.deltaTime);
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        transform.Rotate(rotation);
    }
}
