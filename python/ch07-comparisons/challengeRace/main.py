def has_enough_energy(energy_available, distance_one_way, meters_per_energy):
    energy_needed = (distance_one_way * 2) / meters_per_energy    
    if energy_available >= energy_needed:
        return True
    return False
