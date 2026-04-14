// (c) 2026 max
// this code is overly commented because i am really not well versed in C or SDL, so the comments are
// mainly just for me to read back over once i realise that i have done something completely wrong
// about 5 hours into this. :)

#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

int main(int argc, char* argv[]) {
	printf("maxgte - work in progreeess.\n");
	SDL_Window *window = SDL_CreateWindow( // creating the window
		"maxgte",
		640,
		480,
		SDL_WINDOW_RESIZABLE
	);
	SDL_Surface *surface = SDL_GetWindowSurface(window);
	SDL_Init(SDL_INIT_VIDEO); // init the video signal
	TTF_Init(); // this took like 15 minutes to realise that I need. D'OH!

	if (window == NULL) { // simple error detection, check the window was actually created.
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	// now we are just going to try and render some text
	SDL_Renderer *renderer = SDL_GetRenderer(window);

	TTF_TextEngine *textEngine = TTF_CreateRendererTextEngine(renderer);
	float ptsize = 24;

	TTF_Font *font = TTF_OpenFont("/home/max/Documents/maxgte/font.ttf", ptsize); // font is null
	if (font==NULL){
		printf("font null.\n");
		printf("%s%s", SDL_GetError(), "\n");
	}
	TTF_Text *text = TTF_CreateText(textEngine, font, "max!", 4);
	float x = 50;
	float y = 50;

	TTF_DrawRendererText(text, x, y);
	SDL_UpdateWindowSurface(window);

	bool wants_to_quit = false;

	while (!wants_to_quit) { // run this loop so when the quit signal is fired, we can close the window
		SDL_Event event;     // without having to force quit the window from the OS

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				wants_to_quit = true;
			}
		}
		// logic
	}

	SDL_DestroyWindow(window); // why are you reading this comment? you obviously know what this does.

	SDL_Quit();
	return 0;
}
