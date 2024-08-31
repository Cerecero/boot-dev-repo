def take_magic_damage(health, resist, amp, spell_power):
    health = health - (spell_power * amp - resist)
    return health
