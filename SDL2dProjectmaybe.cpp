#include "App.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


void initSDL(App& app);

void prepareScene(App& app)
{
	SDL_SetRenderDrawColor(app.sdl_renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.sdl_renderer);
}

void presentScene(App& app)
{
	SDL_RenderPresent(app.sdl_renderer);
}

void doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}

int main(int argc, char** argv)
{
    App app;

    initSDL(app);

    while(true)
    {
        prepareScene(app);

		doInput();

		presentScene(app);

		SDL_Delay(16);
    }

    return 0;
}

void initSDL(App& app)
{
    int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.sdl_window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.sdl_window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.sdl_renderer = SDL_CreateRenderer(app.sdl_window, -1, rendererFlags);

	if (!app.sdl_renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}