def new_resizer(max_width, max_height):
    def optional_integrer(min_width=0, min_height=0):
        if min_width > max_width or min_height > max_height:
            raise Exception("minimum size cannot exceed maximum size")

        def resize(width, height):
            resized_width = max(min_width, min(width, max_width))
            resized_height = max(min_height, min(height, max_height))

            return resized_width, resized_height
        return resize
    return optional_integrer
