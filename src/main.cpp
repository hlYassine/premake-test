#include<iostream>
#include"SDL/SDL.h"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        std::cout<<"Échec de l'initialisation de la SDL "<<SDL_GetError()<<std::endl;  
    }

    /* Création de la fenêtre */
    SDL_Window* _Window = NULL;
    _Window = SDL_CreateWindow("Premake test",SDL_WINDOWPOS_UNDEFINED,
                                                  SDL_WINDOWPOS_UNDEFINED,
                                                  640,
                                                  480,
                                                  SDL_WINDOW_SHOWN);

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

    //main loop
    SDL_Event _event;
    bool _exit = false;
    while(!_exit)
    {

	SDL_WaitEvent(&_event);

        if(_event.window.event == SDL_WINDOWEVENT_CLOSE)
		_exit = true;
    }


    if( _Window )
    {
       SDL_DestroyWindow(_Window);
    }

    SDL_Quit();


	return 0;
}
