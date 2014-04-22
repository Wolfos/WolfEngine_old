#include "GameMain.h"
#include "WolfEngine\WolfEngine.h"
#include "Components\Card.h"
#include <algorithm> //Random shuffle
#include <time.h>

SDL_Texture* spritesheet;
int numCards = 15;
GameObject** cards;
Point cardSize;
SDL_Texture* background;

//Called only once when the game starts
void GameMain::Start()
{
	spritesheet = Image::Load("MemoryCards.png", Screen::mainCamera->screen);
	background = Image::Load("Background.png", Screen::mainCamera->screen);
	cards = (GameObject**) calloc(numCards * 2, sizeof(GameObject*));
	if (!cards)
	{
		Debug::Log("Could not allocate memory for cards array");
		return;	
	}
	cardSize.x = 137;
	cardSize.y = 136;

	for (int i = 0; i < numCards * 2; i++)
	{
		cards[i] = ObjectManager::NewGameObject("Card");
		cards[i]->AddComponent<SpriteRenderer>();
		cards[i]->GetComponent<SpriteRenderer>()->spriteSheet = spritesheet;
		cards[i]->GetComponent<SpriteRenderer>()->frame = (i / 2) + 1;
		cards[i]->GetComponent<SpriteRenderer>()->width = cardSize.x;
		cards[i]->GetComponent<SpriteRenderer>()->height = cardSize.y;

		cards[i]->AddComponent<Card>();
	}
	
	int x = 0;
	int y = 0;

	//Set random seed to current time in seconds
	srand(time(0));
	//Shuffle the cards
	std::random_shuffle(&cards[0], &cards[numCards * 2]);

	//Put the cards in a sorted location
	for (int i = 0; i < numCards * 2; i++)
	{
		cards[i]->transform->scale.y = (float)Screen::mainCamera->height / (float)(cardSize.y * 6);
		cards[i]->transform->scale.x = cards[i]->transform->scale.y;
		cards[i]->transform->position.x = (int)(x * (cardSize.x * cards[i]->transform->scale.x));
		cards[i]->transform->position.y = (int)(y * (cardSize.y * cards[i]->transform->scale.y));

		x++;
		if (x >= 5)
		{
			y++;
			x = 0;
		}
	}
}

///
/// The game's main loop
///
void GameMain::Update()
{
	SDL_RenderCopy(Screen::mainCamera->screen, background, 0, 0);
	int selected[2];
	int numSelected = 0;
	for (int i = 0; i < numCards * 2; i++)
	{
		if (cards[i]->GetComponent<Card>()->selected)
		{
			selected[numSelected] = i;
			numSelected++;
			if (numSelected==2)
			{
				//Check if selected cards are the same
				if (cards[selected[0]]->GetComponent<Card>()->card == cards[selected[1]]->GetComponent<Card>()->card)
				{
					cards[selected[0]]->GetComponent<Card>()->checked = true;
					cards[selected[1]]->GetComponent<Card>()->checked = true;

					cards[selected[0]]->GetComponent<Card>()->selected = false;
					cards[selected[1]]->GetComponent<Card>()->selected = false;
				}
				else
				{
					cards[selected[0]]->GetComponent<Card>()->Reset();
					cards[selected[1]]->GetComponent<Card>()->Reset();
					numSelected = 0;
				}
			}
		}
	}
}
void GameMain::Exit()
{
	free(cards);
	SDL_DestroyTexture(spritesheet);
	SDL_DestroyTexture(background);
}
