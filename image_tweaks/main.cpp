#include <iostream>

#include <stdbool.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

void tweak5(uint32_t &location) // in situ
{
    const uint8_t tmp1 = (location & 0x000000FF);
    const uint8_t tmp2 = (location & 0x00FF0000) >> 16;

    location &= 0xFF00FF00;

    location += tmp1 << 16;
    location += tmp2;
}

void tweak4(uint32_t &location) // in situ
{
    uint32_t tmp1 = location & 0x000000FF;
    uint32_t tmp2 = location & 0x00FF0000;

    location &= 0xFF00FF00;

    location += tmp1 << 16;
    location += tmp2 >> 16;
}

int tweak3(uint32_t location)
{
    uint32_t tmp1 = location & 0x000000FF;
    uint32_t tmp2 = location & 0x00FF0000;

    location &= 0xFF00FF00;

    location += tmp1 << 16;
    location += tmp2 >> 16;

    return location;
}

int tweak2(uint32_t location)
{
    uint32_t tmp = 0;

    const uint32_t blue_mask = 0x000000FF;
    const uint32_t green_mask = 0x0000FF00;
    const uint32_t red_mask = 0x00FF0000;
    const uint32_t alpha_mask = 0xFF000000;

    tmp |= location & alpha_mask;
    tmp |= (location & red_mask) >> 16;
    tmp |= location & green_mask;
    tmp |= (location & blue_mask) << 16;

    return tmp;
}

int tweak(uint32_t location)
{
    uint32_t tmp = 0;

    const uint32_t blue_mask = 0x000000FF;
    const uint32_t green_mask = 0x0000FF00;
    const uint32_t red_mask = 0x00FF0000;
    const uint32_t alpha_mask = 0xFF000000;

    uint32_t blue_channel = location & blue_mask;
    uint32_t green_channel = location & green_mask;
    uint32_t red_channel = location & red_mask;
    uint32_t alpha_channel = location & alpha_mask;

    tmp |= (alpha_channel);
    tmp |= (red_channel >> 16);
    tmp |= (green_channel);
    tmp |= (blue_channel << 16);

    return tmp;
}

void bgra_to_rgba2(int W, int H, uint32_t *p) // adjust image channels in place
{
    for (int row = 0; row < H; ++row)
    {
        for (int column = 0; column < W; ++column)
        {
            // p[(row * W) + column] = tweak3(p[(row * W) + column]);   // v 1, 2, 3
            tweak5(p[(row * W) + column]); // v 4, 5
        }
    }
}

void bgra_to_rgba(int W, int H, uint32_t *p) // adjust image channels in place
{

    int length = W * H;

    for (int pos = 0; pos < length; ++pos)
    {
        tweak5(p[pos]);
    }
}

int main(int, char **)
{
    std::cout << "image tweak!\n";

    int width, height, channels;
    unsigned char *data = stbi_load("input.png", &width, &height, &channels, 0);

    bgra_to_rgba(width, height, (uint32_t *)data);

    stbi_write_png("output.png", width, height, channels, data, width * channels);

    return 0;
}
