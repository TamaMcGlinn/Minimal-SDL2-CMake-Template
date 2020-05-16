#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void runSDL(){
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  if (window == NULL){
    SDL_ShowSimpleMessageBox(0, "Window init error", SDL_GetError(), window);
  }    
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL){
    SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), window);
  }
  SDL_Surface * image = SDL_LoadBMP("assets/hello_world.bmp");
  if (image == NULL){ 
    SDL_ShowSimpleMessageBox(0, "Image init error", SDL_GetError(), window);
  }
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
  if (texture == NULL){
    SDL_ShowSimpleMessageBox(0, "Texture init error", SDL_GetError(), window);
  }

  while (!quit){
     SDL_WaitEvent(&event);
     switch(event.type)
     {
     case SDL_QUIT:
         quit = true;
         break;
     }
     SDL_RenderCopy(renderer, texture, NULL, NULL);
     SDL_RenderPresent(renderer);
  }        

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
}
