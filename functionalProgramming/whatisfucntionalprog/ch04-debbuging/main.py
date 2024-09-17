def format_line(line):
    strip = line.strip()
    upper = strip.upper()
    rm_periods = upper.replace('.', '')
    suffix = f"{rm_periods}..."
    return suffix
