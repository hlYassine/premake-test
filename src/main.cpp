#include<iostream>
#include"SDL/SDL.h"

int main(int argc, char** argv)
{

#ifdef MY_DEBUG
   int numdrivers = SDL_GetNumVideoDrivers();
   int working = 0;
   const char* drivername;

     for (int i = 0; i < numdrivers; ++i) {
       drivername = SDL_GetVideoDriver(i);

      if (SDL_VideoInit(drivername) == 0) {
         SDL_VideoQuit();
         ++working;
         printf("Driver %s works.\n", drivername);
       }
       else {
         printf("Driver %s doesn't work.\n", drivername);
      }
    }
     printf("\n%d video drivers total (%d work)\n", numdrivers, working);
#endif

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
	std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	return 1;
}

  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
if (win == 0){
	std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	return 1;
}

SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
if (ren == 0){
	std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
	return 1;
}

SDL_Surface *bmp = SDL_LoadBMP("../../resources/hello.bmp");
if (bmp == 0){
	std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
	return 1;
}

SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
SDL_FreeSurface(bmp);
if (tex == 0){
	std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
	return 1;
}

SDL_Event _event;
bool _exit = false;

while(!_exit)
{
	SDL_WaitEvent(&_event);

	if(_event.window.event == SDL_WINDOWEVENT_CLOSE)
           _exit = true;

	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, NULL, NULL);
	SDL_RenderPresent(ren);
}

SDL_DestroyTexture(tex);
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();



	return 0;
}
