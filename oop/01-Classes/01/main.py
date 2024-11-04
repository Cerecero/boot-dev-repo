def destroy_walls(wall_health):
    for w in wall_health:
        if w <= 0:
            wall_health.remove(w)
    return wall_health

