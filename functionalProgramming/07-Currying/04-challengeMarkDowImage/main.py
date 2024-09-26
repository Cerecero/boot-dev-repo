def create_markdown_image(alt_text):
    def with_url(url):
        escaped_url = url.replace("(", "%28").replace(")", "%29")

        markdown_image = f"![{alt_text}]({escaped_url})"

        def with_title(title=None):
            if title:
                markdown_image_with_title = markdown_image[:-
                                                           1] + f' "{title}")'
                return markdown_image_with_title
            return markdown_image

        return with_title

    return with_url
