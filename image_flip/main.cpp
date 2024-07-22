#include <iostream>

#include <stdbool.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

void vertical_flip(int W, int H, uint32_t *p)
{
    for (int row = 0; row < H/2; ++row)
    {
        for (int column = 0; column < W; ++column)
        {
            uint32_t tmp = p[(row * W) + column];
            p[(row * W) + column] = p[((W-row) * W) + column];
            p[((W-row) * W) + column] = tmp;
        }
    }
}

int main(int, char **)
{
    std::cout << "image tweak!\n";

    int width, height, channels;
    unsigned char *data = stbi_load("input.png", &width, &height, &channels, 0);

    vertical_flip(width, height, (uint32_t *)data);

    stbi_write_png("output.png", width, height, channels, data, width * channels);

    return 0;
}
