def css_styles(initial_styles):
    copy_styles = initial_styles.copy()

    def add_style(selector, property, value):
        if selector not in copy_styles:
            copy_styles[selector] = {}
        copy_styles[selector][property] = value
        return copy_styles

    return add_style
