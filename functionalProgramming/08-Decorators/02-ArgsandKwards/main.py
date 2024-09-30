def args_logger(*args, **kwargs):
    count = 0
    for arg in args:
        count += 1
        print(f"{count}. {arg}")
    for key, value in sorted(kwargs.items()):
        print(f"* {key}: {value}")
