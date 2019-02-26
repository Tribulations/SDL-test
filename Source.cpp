#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

SDL_Texture* loadTexture(std::string filePath);

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Texture* gTexture;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int SQUARE_WIDTH = 100;
const int SQUARE_HEIGHT = 100;

/*
class LTexture
{
	public:
		LTexture();
	
		~LTexture();
	
	
};
*/


SDL_Texture* loadTexture(std::string filePath)
{
	

	SDL_Surface* loadedSurface = IMG_Load( filePath.c_str() );

	SDL_Texture* newTexture = NULL;
	

	if (loadedSurface = NULL)
	{
		std::cerr << "Failed to load image! IMG Error: " << IMG_GetError() << std::endl;
		
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			std::cerr << "Unable to create texture from surface. IMG Error: " << filePath.c_str() <<  IMG_GetError() << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
	}
	
	
	

	return newTexture;
}

int main(int argv, char* argc[])
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	

	gWindow = SDL_CreateWindow("Window Testr", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

	bool quit = false;

	SDL_Event e;

	SDL_Rect rect = { 50,50,50,50 };
	SDL_Point point = { 320,320 };
	
	
	gTexture = loadTexture("bild.png");
	

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
		SDL_RenderClear(gRenderer);

		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(gRenderer, &rect);

		
		SDL_RenderDrawLine(gRenderer, 150, 150, 250, 150);
		SDL_RenderDrawLine(gRenderer, 150, 151, 250, 151);
		SDL_RenderDrawLine(gRenderer, 150, 152, 250, 152);
		SDL_RenderDrawLine(gRenderer, 150, 153, 250, 153);
		
		SDL_RenderDrawPoints(gRenderer, &point, 1);

		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
		SDL_RenderPresent(gRenderer);
	}
	
	
	getchar();
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;

	SDL_Quit();

	return 0;

}
