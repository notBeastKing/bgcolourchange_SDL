#include<iostream>
#include<screen.h>

using namespace std;
using namespace dingus;

int main(int argc, char *argv[])
{
   screan pixels;

   pixels.createscreen();

   pixels.create_rend_texture();

    pixels.setbuffer(0,0,0);

   pixels.process_events();

   int hex1 = 0x00, hex2 = 0x00, hex3= 0x00;
   
   bool run = true;
   SDL_Event event;

   while(run == true)
   {
    while(SDL_PollEvent(&event))
    {
        pixels.setbuffer(hex1++, hex2 += 2, hex3+= 5);

        pixels.process_events();
        if(event.type == SDL_QUIT)
        {
            run = false;
        }
        if(hex1 == 255)
        {
            pixels.setbuffer(0,hex2,hex3);
        }
        else
        {
            if(hex2 == 255)
            {
                pixels.setbuffer(hex1,0,hex3);
            }
            else
            {
                if(hex3 == 255)
                {
                    pixels.setbuffer(hex1,hex2,0);
                }
            }
        }
        
    }
   }

   pixels.close();

   return 0;

   }