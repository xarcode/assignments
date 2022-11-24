using System.Collections;
using UnityEngine;

public class Player : MonoBehaviour
{
    public PlayerSpriteRenderer smallRenderer;
    public PlayerSpriteRenderer bigRenderer;
    private PlayerSpriteRenderer activeRenderer;

    public CapsuleCollider2D capsuleCollider { get; private set; }
    // public DeathAnimation deathAnimation { get; private set; }

    private void Awake()
    {
        capsuleCollider = GetComponent<CapsuleCollider2D>();
        // deathAnimation = GetComponent<DeathAnimation>();
        activeRenderer = smallRenderer;
    }

}
