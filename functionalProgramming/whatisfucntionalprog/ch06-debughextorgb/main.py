def hex_to_rgb(hex_color):
    if not is_hexadecimal(hex_color):
        raise Exception("not a hex color string")
    r_color = int(hex_color[:2], base=16)
    g_color = int(hex_color[2:4], base=16)
    b_color = int(hex_color[4:], base=16)
    # print(f"this is r g b color: {r_color},{g_color}, {b_color}")
    return r_color, g_color, b_color


def is_hexadecimal(hex_string):
    try:
        int(hex_string, base=16)
        return True
    except Exception:
        raise False
