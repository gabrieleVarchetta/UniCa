using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private Rigidbody sphereRB;

    [SerializeField]
    float speed = 5f;
    float jump_speed = 250f;
    bool can_jump = true;
    int score = 0;
    [SerializeField]
    List<TextMeshProUGUI> wall_texts;
    [SerializeField]
    private TextMeshProUGUI score_text;

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
        float jump = Input.GetAxis("Jump");

        Vector3 force = new(horizontalInput * speed, can_jump ? jump * jump_speed : 0f, verticalInput * speed);

        sphereRB.AddForce(force, ForceMode.Acceleration);
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.CompareTag("Collectable"))
        {
            //Destroy(other.gameObject);
            other.gameObject.SetActive(false);
            score += 10;
            UpdateScore(score);
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.CompareTag("Terrain"))
            can_jump = true;
    }

    private void OnCollisionExit(Collision collision)
    {
        if(collision.gameObject.CompareTag("Terrain"))
            can_jump = false;
    }

    private void UpdateScore(int score)
    {
        score_text.SetText("SCORE: " + score);
        foreach (TextMeshProUGUI text in wall_texts)
            text.SetText("SCORE: " + score);
    }
}
